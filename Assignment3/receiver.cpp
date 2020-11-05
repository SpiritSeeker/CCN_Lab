#include "Socket/SocketServer.h"
#include <vector>
#include <chrono>
#include <thread>
#include <random>

int main()
{
	std::vector<std::string> receivedData;

	std::default_random_engine randomGenerator;
	std::uniform_int_distribution<int> uniformDistribution(0, 99);
	int randomNumber;

	auto server = Socket::SocketServer::Create();

	server->Bind();
	server->Accept();

	while (true)
	{
		std::string data = server->Read();

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		randomNumber = uniformDistribution(randomGenerator);
		
		if (randomNumber)
		{
			server->Send("ACK");
			if (data == "\n") break;
			receivedData.push_back(data);
			std::cout << data << std::endl;
		}
		else
		{
			server->Send("NACK");
			std::cout << "\033[01;31mNACK\033[00;39m" << std::endl;
		}
	}

	return 0;
}