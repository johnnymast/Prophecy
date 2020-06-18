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

	pchheader "compiled.h"
	pchsource "Prophecy/Prophecy/src/compiled.cpp"

	files
	{
		"%{prj.name}/Prophecy/src/**.h",
		"%{prj.name}/Prophecy/src/**.cpp"
	}

	includedirs
	{
	    "%{prj.name}/Prophecy/src",
		"%{prj.name}/Prophecy/vendor/spdlog/include"
		"%{prj.name}/Prophecy/vendor/glfw/include"
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
		"Prophecy/Prophecy/vendor/spdlog/include",
		"Prophecy/Prophecy/vendor/glfw/include",
		"Prophecy/Prophecy/src"
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
