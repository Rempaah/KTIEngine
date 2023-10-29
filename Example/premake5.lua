project "Example"
		kind "ConsoleApp"
		language "C++"

		defines { "SFML_STATIC" }

		files { "**.h", "**.cpp" }

		includedirs { "%{includeDir.SFML}", "%{includeDir.PhysicsEngine}" }

		targetdir ("../bin/" .. outputDir .. "%{prj.name}")
		objdir ("../bin-int/" .. outputDir .. "%{prj.name}")

		
		filter "configurations:Debug"
			defines "DEBUG"
			symbols "On"
			libdirs { "%{libDir.SFMLD}" }
			links {
				"PhysicsEngine",
				"gdi32.lib",
				"winmm.lib",
				"opengl32.lib",
				"freetype.lib",
				"sfml-graphics-s-d.lib",
				"sfml-system-s-d.lib",
				"sfml-window-s-d.lib"
			}
		
		filter "configurations:Release"
			defines "RELEASE"
			optimize "On"
			libdirs { "%{libDir.SFMLND}" }
			links {
				"PhysicsEngine",
				"gdi32.lib",
				"winmm.lib",
				"opengl32.lib",
				"freetype.lib",
				"sfml-graphics-s.lib",
				"sfml-system-s.lib",
				"sfml-window-s.lib"
			}