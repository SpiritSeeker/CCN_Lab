project "server"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/")
	objdir ("bin-int/")

	files
	{
		"server.cpp"
	}

	includedirs
	{
		"../src"
	}

project "client"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/")
	objdir ("bin-int/")

	files
	{
		"client.cpp"
	}

	includedirs
	{
		"../src"
	}