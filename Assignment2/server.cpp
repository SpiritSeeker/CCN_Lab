#include "Socket/SocketServer.h"

int main()
{
	auto server = Socket::SocketServer::Create();

	server->Bind();
	server->Accept();

	auto buffer = server->Read();
	std::cout << buffer->Data << std::endl;

	server->Send("Message received! :)");

	return 0;
}