#include "Socket/SocketClient.h"

int main()
{
	auto client = Socket::SocketClient::Create();

	client->Connect();

	client->Send("Hello from client!");
	auto buffer = client->Read();
	std::cout << buffer->Data << std::endl;

	return 0;
}