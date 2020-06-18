workspace "Prophecy"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

    flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Prophecy"
	location "Prophecy"
	kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "compile.h"
	pchsource "Prophecy/src/compile.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
	    "%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{

		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Client")
		}

	filter "configurations:Debug"
		defines "PR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PR_DIST"
		optimize "On"

project "Client"
	location "Client"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Prophecy/vendor/spdlog/include",
		"Prophecy/src"
	}

	links
	{
		"Prophecy"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{

		}

	filter "configurations:Debug"
		defines "PR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PR_DIST"
		optimize "On"
