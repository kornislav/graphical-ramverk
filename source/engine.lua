
project("grv")
	kind "SharedLib"
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
		"%{prj.location}/grv"
	}

	libdirs {
		"%{prj.location}../lib"
	}

	defines {
		"_EXPORT"
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
			"opengl32",
			"glew32s"
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