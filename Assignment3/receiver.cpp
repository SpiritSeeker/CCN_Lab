#include "Socket/SocketClient.h"
#include <vector>

int main()
{
	std::vector<std::string> receivedData;

	auto client = Socket::SocketClient::Create();
	client->Connect();

	while (true)
	{
		auto buffer = client->Read();
		client->Send("ACK");
		receivedData.push_back(buffer);
		std::cout << buffer << " ";
		if (buffer == "\n") break;
	}

	return 0;
}