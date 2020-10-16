#include "Socket/SocketServer.h"

int main()
{
	auto server = Socket::SocketServer::Create();

	server->Bind();
	server->Accept();

	std::string data = server->Read();
	std::cout << "\033[32mMessage from client:\033[00;39m " << data << std::endl;

	server->Send("Message received! :)");

	return 0;
}