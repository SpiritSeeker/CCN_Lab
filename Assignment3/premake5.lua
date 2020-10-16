project "sender"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/")
	objdir ("bin-int/")

	files
	{
		"sender.cpp"
	}

	includedirs
	{
		"../src"
	}

project "receiver"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/")
	objdir ("bin-int/")

	files
	{
		"receiver.cpp"
	}

	includedirs
	{
		"../src"
	}