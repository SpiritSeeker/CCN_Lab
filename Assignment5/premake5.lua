project "dijkstras"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/")
	objdir ("bin-int/")

	files
	{
		"dijkstras.cpp",
		"Graph.h",
		"Graph.cpp"
	}
