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

		std::string Read();
		void Send(const std::string& message);

		static Ref<SocketClient> Create(const SocketClientProps& clientProps = SocketClientProps());
	private:
		SocketClientProps m_Props;
		int m_Domain;
		int m_ClientDescriptor;
	};

	SocketClient::SocketClient(const SocketClientProps& clientProps)
		: m_Props(clientProps)
	{
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

	std::string SocketClient::Read()
	{
		char *buffer = new char[m_Props.BufferSize];
		read(m_ClientDescriptor, buffer, m_Props.BufferSize);

		std::string data(buffer);
		delete[] buffer;

		return data;
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