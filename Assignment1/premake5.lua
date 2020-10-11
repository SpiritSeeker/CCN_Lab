project "poisson"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/")
	objdir ("bin-int/")

	files
	{
		"poisson.cpp"
	}

	includedirs
	{
		"/usr/include/python3.5m",  -- Replace with your Python version
		"../vendor/matplotlib-cpp"
	}

	links
	{
		"python3.5m"  -- Replace with your Python version
	}

project "pareto"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/")
	objdir ("bin-int/")

	files
	{
		"pareto.cpp"
	}

	includedirs
	{
		"/usr/include/python3.5m",  -- Replace with your Python version
		"../vendor/matplotlib-cpp"
	}

	links
	{
		"python3.5m"  -- Replace with your Python version
	}