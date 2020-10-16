#include "Socket/SocketServer.h"

int main()
{
	auto server = Socket::SocketServer::Create();

	server->Bind();
	server->Accept();

	std::string data = server->Read();
	std::cout << data << std::endl;

	server->Send("Message received! :)");

	return 0;
}