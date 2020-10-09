#pragma once

#include "SocketCore.h"

namespace Socket {

	struct SocketClientProps
	{
		bool UseTCP = true;
		bool UseIPv6 = false;
		uint32_t Port = 8080;
		uint32_t BufferSize = 1024;
	};

	class SocketClient
	{
	public:
		SocketClient(const SocketClientProps& clientProps);
		~SocketClient() = default;

		void Connect(const std::string& address = "127.0.0.1");

		const Ref<Buffer>& Read();
		void Send(const std::string& message);

		const Ref<Buffer>& GetBuffer() { return m_Buffer; }

		static Ref<SocketClient> Create(const SocketClientProps& clientProps = SocketClientProps());
	private:
		SocketClientProps m_Props;
		Ref<Buffer> m_Buffer;
		int m_Domain;
		int m_ClientDescriptor;
	};

	SocketClient::SocketClient(const SocketClientProps& clientProps)
		: m_Props(clientProps)
	{
		m_Buffer = CreateRef<Buffer>();
		m_Buffer->BufferSize = m_Props.BufferSize;

		m_Domain = m_Props.UseIPv6 ? AF_INET6 : AF_INET;
		int connectionType = m_Props.UseTCP ? SOCK_STREAM : SOCK_DGRAM;

		if ((m_ClientDescriptor = socket(m_Domain, connectionType, 0)) < 0)
		{
			SOCKET_ERROR("CLIENT ERROR: Socket creation failed!");
			return;
		}
	}

	void SocketClient::Connect(const std::string& address)
	{
		struct sockaddr_in serverAddress;
		serverAddress.sin_family = m_Domain;
		serverAddress.sin_port = htons(m_Props.Port);

		if (inet_pton(m_Domain, address.c_str(), &serverAddress.sin_addr) <= 0)
		{
			SOCKET_ERROR("CLIENT ERROR: Invalid server address!");
			return;
		}

		if (connect(m_ClientDescriptor, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
		{
			SOCKET_ERROR("CLIENT ERROR: Failed to connect to server!");
			return;
		}

		std::string message = "CLIENT INFO: Connected to " + address;
		SOCKET_INFO(message);
	}

	const Ref<Buffer>& SocketClient::Read()
	{
		char *buffer = new char[m_Buffer->BufferSize];
		read(m_ClientDescriptor, buffer, m_Buffer->BufferSize);

		m_Buffer->Data = buffer;
		delete[] buffer;

		return m_Buffer;
	}

	void SocketClient::Send(const std::string& message)
	{
		send(m_ClientDescriptor, message.c_str(), message.size(), 0);
	}

	Ref<SocketClient> SocketClient::Create(const SocketClientProps& clientProps)
	{
		return CreateRef<SocketClient>(clientProps);
	}



}