workspace "KaryaTulisIlmiah"
	architecture "x64"
	configurations { "Debug", "Release" }
	startproject "Example"

	project "Example"
		location "Example"

		kind "ConsoleApp"
		language "C++"

		files { "Example/**.h", "Example/**.cpp" }

		targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
		objdir ("bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

		links "PhysicsEngine"

		filter "configurations:Debug"
			defines "DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "RELEASE"
			optimize "On"
	project "PhysicsEngine"
		location "PhysicsEngine"

		kind "StaticLib"
		language "C++"

		files { "PhysicsEngine/**.h", "PhysicsEngine/**.cpp" }

		targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
		objdir ("bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

		filter "configurations:Debug"
			defines "DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "RELEASE"
			optimize "On"