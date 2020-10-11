#include "Socket/SocketServer.h"
#include <vector>

int main()
{
	std::vector<std::string> data = { "11", 
									"2",
									"3",
									"4",
									"5",
									"\n" };
	int dataLength = data.size();

	auto server = Socket::SocketServer::Create();

	server->Bind();
	server->Accept();

	int dataIndex = 0;
	while (dataIndex != dataLength)
	{
		server->Send(data[dataIndex]);

		auto buffer = server->Read();
		if (buffer->Data == "ACK") dataIndex++;
	}

	return 0;
}