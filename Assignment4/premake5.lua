project "send"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/")
	objdir ("bin-int/")

	files
	{
		"send.cpp"
	}

	includedirs
	{
		"../src"
	}

project "recv"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/")
	objdir ("bin-int/")

	files
	{
		"recv.cpp"
	}

	includedirs
	{
		"../src"
	}