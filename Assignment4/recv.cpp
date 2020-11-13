#include "Socket/SocketServer.h"
#include <vector>
#include <chrono>
#include <thread>
#include <random>
#include <list>

int main()
{
	std::vector<std::string> receivedData;

	int windowSize = 5;
	std::list<std::string> acks;

	std::default_random_engine randomGenerator;
	std::uniform_int_distribution<int> uniformDistribution(0, 99);
	int randomNumber;

	auto server = Socket::SocketServer::Create();

	server->Bind();
	server->Accept();

	while (true)
	{
		for (int i = 0; i < windowSize; i++)
		{
			std::string data = server->Read();

			randomNumber = uniformDistribution(randomGenerator);
			
			if (randomNumber)
			{
				acks.push_back("ACK");
				if (data == "\n") break;
				receivedData.push_back(data);
				std::cout << data << std::endl;
			}
			else
			{
				acks.push_back("NACK");
				std::cout << "\033[01;31mNACK\033[00;39m" << std::endl;
				for (int j = i + 1; j < windowSize; j++) server->Read();
				break;
			}
		}

		while (!acks.empty())
		{
			server->Send(acks.front());
			acks.pop_front();
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}

	return 0;
}