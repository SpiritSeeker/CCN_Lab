#include "Socket/SocketClient.h"
#include <vector>

int main()
{
	std::vector<std::string> data = { "Two", "plus", "two", "is", "four", "minus", "one", "that\'s", "three", "quick", "mafs", " ",
									"Everyday", "man\'s", "on", "the", "block", "smoke", "trees", " ",
									"See", "your", "girl", "in", "the", "park", "that", "girl", "is", "a", "uckers", " ",
									"The", "ting", "goes", "skrrrahh", "pap", "pap", "ka", "ka", "ka", " ",
									"Skidiki", "pap", "pap", "and", "a", "pu", "pu", "pudrrrr", "boom", " ",
									"Skya", "du", "du", "ku", "ku", "dun", "dun", " ",
									"Poom", "Poom", " ",
									"Big", "Shaq", "one", "and", "only"
									"\n" };
	int dataLength = data.size();

	auto client = Socket::SocketClient::Create();
	client->Connect();

	int dataIndex = 0;
	while (dataIndex != dataLength)
	{
		client->Send(data[dataIndex]);

		std::string data = client->Read();
		if (data == "ACK")
		{
			dataIndex++;
			std::cout << "\033[32mACK Received: Sending next data packet!\033[00;39m" << std::endl;
		}
		if (data == "NACK")
			std::cout << "\033[01;31mTIMEOUT: ACK not received, resending last packet!\033[00;39m" << std::endl;
	}

	return 0;
}