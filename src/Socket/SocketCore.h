#pragma once

#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <string>
#include <memory>
#include <iostream>

namespace Socket {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	void SOCKET_ERROR(const std::string& message)
	{
		std::cout << "\033[01;31m" << message << "\033[00;39m" << std::endl;
	}

	void SOCKET_WARN(const std::string& message)
	{
		std::cout << "\033[01;31m" << message << "\033[00;39m" << std::endl;
	}

	void SOCKET_INFO(const std::string& message)
	{
		std::cout << "\033[32m" << message << "\033[00;39m" << std::endl;
	}	

}
