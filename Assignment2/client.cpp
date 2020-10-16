#include "Socket/SocketClient.h"

int main()
{
	auto client = Socket::SocketClient::Create();

	client->Connect();

	client->Send("Hello from client!");
	std::string data = client->Read();
	std::cout << data << std::endl;

	return 0;
}