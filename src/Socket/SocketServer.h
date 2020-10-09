#pragma once

#include "SocketCore.h"

namespace Socket {

	struct SocketServerProps
	{
		bool UseTCP = true;
		bool UseIPv6 = false;
		uint32_t Port = 8080;
		uint32_t BufferSize = 1024;
	};

	class SocketServer
	{
	public:
		SocketServer(const SocketServerProps& serverProps);
		~SocketServer() = default;

		void Bind(int queueLength = 3);
		int Accept();

		const Ref<Buffer>& Read(int socket = -1);
		void Send(const std::string& message, int socket = -1);

		const Ref<Buffer>& GetBuffer() { return m_Buffer; }

		static Ref<SocketServer> Create(const SocketServerProps& serverProps = SocketServerProps());
	private:
		SocketServerProps m_Props;
		Ref<Buffer> m_Buffer;
		int m_Domain;
		int m_ServerDescriptor;
		struct sockaddr_in m_Address;
		int activeConnection = -1;
	};

	SocketServer::SocketServer(const SocketServerProps& serverProps)
		: m_Props(serverProps)
	{
		m_Buffer = CreateRef<Buffer>();
		m_Buffer->BufferSize = m_Props.BufferSize;

		m_Domain = m_Props.UseIPv6 ? AF_INET6 : AF_INET;
		int connectionType = m_Props.UseTCP ? SOCK_STREAM : SOCK_DGRAM;

		if ((m_ServerDescriptor = socket(m_Domain, connectionType, 0)) == 0)
		{
			SOCKET_ERROR("SERVER ERROR: Socket creation failed!");
			return;
		}

		int opt = 1;
		if (setsockopt(m_ServerDescriptor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
		{
			SOCKET_ERROR("SERVER ERROR: Failed to add options to socket!");
			return;
		}
	}

	void SocketServer::Bind(int queueLength)
	{
		int addressLength = sizeof(m_Address);

		m_Address.sin_family = m_Domain;
		m_Address.sin_addr.s_addr = INADDR_ANY;
		m_Address.sin_port = htons(m_Props.Port);

		if (bind(m_ServerDescriptor, (struct sockaddr*)&m_Address, addressLength) < 0)
		{
			SOCKET_ERROR("SERVER ERROR: Failed to bind!");
			return;
		}

		if (listen(m_ServerDescriptor, queueLength) < 0)
		{
			SOCKET_ERROR("SERVER ERROR: Failed to start listening for connections!");
			return;
		}

		SOCKET_INFO("SERVER INFO: Listening for connections!");
	}

	int SocketServer::Accept()
	{
		int addressLength = sizeof(m_Address);
		int newSocket;

		if ((newSocket = accept(m_ServerDescriptor, (struct sockaddr*)&m_Address, (socklen_t*)&addressLength)) < 0)
		{
			SOCKET_ERROR("SERVER ERROR: Failed to accept new connection!");
			return -1;
		}

		activeConnection = newSocket;
		return newSocket;
	}

	const Ref<Buffer>& SocketServer::Read(int socket)
	{
		if (socket == -1) socket = activeConnection;
		if (socket == -1)
		{
			SOCKET_ERROR("SERVER ERROR: No active connection to read!");
			return m_Buffer;
		}

		char *buffer = new char[m_Buffer->BufferSize];
		read(socket, buffer, m_Buffer->BufferSize);

		m_Buffer->Data = buffer;
		delete[] buffer;

		return m_Buffer;
	}

	void SocketServer::Send(const std::string& message, int socket)
	{
		if (socket == -1) socket = activeConnection;
		if (socket == -1)
		{
			SOCKET_ERROR("SERVER ERROR: No active connection to send to!");
			return;
		}

		send(socket, message.c_str(), message.size(), 0);
	}

	Ref<SocketServer> SocketServer::Create(const SocketServerProps& serverProps)
	{
		return CreateRef<SocketServer>(serverProps);
	}



}