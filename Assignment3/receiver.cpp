#include "Socket/SocketClient.h"
#include <vector>

int main()
{
	std::vector<std::string> receivedData;

	auto client = Socket::SocketClient::Create();
	client->Connect();

	while (true)
	{
		std::string data = client->Read();
		client->Send("ACK");
		receivedData.push_back(data);
		std::cout << data << " ";
		if (data == "\n") break;
	}

	return 0;
}