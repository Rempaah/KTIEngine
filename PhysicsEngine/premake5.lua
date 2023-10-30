project "PhysicsEngine"
		kind "StaticLib"
		language "C++"
		cppdialect "C++latest"

		files { "**.h", "**.cpp" }

		includedirs { "%{includeDir.PhysicsEngine}" }

		targetdir ("../bin/" .. outputDir .. "%{prj.name}")
		objdir ("../bin-int/" .. outputDir .. "%{prj.name}")

		filter "configurations:Debug"
			defines "DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "RELEASE"
			optimize "On"