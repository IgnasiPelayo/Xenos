
workspace "Xenos"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Xenos"
	location "Xenos"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"XE_PLATFORM_WINDOWS",
			"XE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "XE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "XE_RELEASE"
		symbols "On"

	filter "configurations:Distribution"
		defines "XE_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
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
		"Xenos/vendor/spdlog/include",
		"Xenos/src"
	}

	links
	{
		"Xenos"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"XE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "XE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "XE_RELEASE"
		symbols "On"

	filter "configurations:Distribution"
		defines "XE_DIST"
		symbols "On"