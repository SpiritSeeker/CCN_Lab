#include "Socket/SocketClient.h"

int main()
{
	auto client = Socket::SocketClient::Create();

	client->Connect();

	std::string message;
	std::cout << "Enter a message: ";
	std::getline(std::cin, message);

	client->Send(message);
	std::string data = client->Read();
	std::cout << "\033[32mMessage from server:\033[00;39m " << data << std::endl;

	return 0;
}