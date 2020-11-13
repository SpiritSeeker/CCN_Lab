#include "Socket/SocketClient.h"
#include <vector>
#include <chrono>
#include <thread>

int main()
{
	std::vector<std::string> data = { "Two", "plus", "two", "is", "four", "minus", "one", "that\'s", "three", "quick", "mafs", " ",
									"Everyday", "man\'s", "on", "the", "block", "smoke", "trees", " ",
									"See", "your", "girl", "in", "the", "park", "that", "girl", "is", "a", "uckers", " ",
									"The", "ting", "goes", "skrrrahh", "pap", "pap", "ka", "ka", "ka", " ",
									"Skidiki", "pap", "pap", "and", "a", "pu", "pu", "pudrrrr", "boom", " ",
									"Skya", "du", "du", "ku", "ku", "dun", "dun", " ",
									"Poom", "Poom", " ",
									"Big", "Shaq", "one", "and", "only",
									"\n" };
	int dataLength = data.size();

	int windowSize = 5;

	auto client = Socket::SocketClient::Create();
	client->Connect();

	int sentDataIndex = 0;
	int recvDataIndex = 0;
	while (recvDataIndex != dataLength)
	{
		for (int i = 0; (i < windowSize) && (sentDataIndex < dataLength); i++)
		{
			std::string outputData = data[sentDataIndex];
			sentDataIndex++;
			std::cout << sentDataIndex << " " << outputData << std::endl;
			client->Send(outputData);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}

		for (int i = 0; (i < windowSize) && (recvDataIndex < dataLength); i++)
		{
			std::string data = client->Read();
			if (data == "ACK")
			{
				recvDataIndex++;
				std::cout << "\033[32mPacket " << i << " ACK Received: Sending next data packet!\033[00;39m" << std::endl;
			}
			if (data == "NACK")
			{
				sentDataIndex = recvDataIndex;
				std::cout << "\033[01;31mTIMEOUT: Packet " << i << " ACK not received, resending last packet!\033[00;39m" << std::endl;
				break;
			}
		}
	}

	return 0;
}