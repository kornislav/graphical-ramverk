project("dev_app")
	kind "WindowedApp"
	language "C++"
	files {
		"code/**.c",
		"code/**.cpp",
		"code/**.h",
		"code/**.hpp",
		"code/**.inl",
	}

	targetdir "%{prj.location}../bin/"
	targetname "%{prj.name}_%{cfg.architecture}"
	debugdir "$%{prj.location}../bin/"
	objdir "%{prj.location}../build/"

	includedirs {
		"%{prj.location}",
		"%{prj.location}/dev_app"
	}

	libdirs {
		"%{prj.location}../lib"
	}

	-- Global per-configuration settings.
	filter { "configurations:Debug" }
		targetsuffix "d"
		defines {
			"_DEBUG",
			"DEBUG",
		}
		flags {
			"Symbols",
		}

	filter { "configurations:Release" }
		targetsuffix "r"
		defines {
			"RELEASE",
			"NDEBUG",
		}
		flags {
			"Symbols",
			"OptimizeSpeed",
		}

	filter { "configurations:Final" }
		defines {
			"FINAL",
			"NDEBUG",
		}
		flags {
			"OptimizeSpeed",
		}

	-- Win32
	filter { "platforms:Win32" }
		system "windows"
		architecture "x86"
		defines {
			"WIN32",
			"_WINDOWS",
		}
		links {
			"grv"
		}

	filter { "platforms:Win32", "configurations:not Debug" }
		buildoptions {
			-- Whole program optimization
			"/GL"
		}
		linkoptions {
			-- Link-time code generation
			"/LTCG"
		}