project "GLFW"
  kind "StaticLib"
  language "C"

	targetdir ("bin/" .. outdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outdir .. "/%{prj.name}")

  files {
    "GLFW/include/GLFW/glfw3.h",
		"GLFW/include/GLFW/glfw3native.h",
		"GLFW/src/glfw_config.h",
		"GLFW/src/context.c",
		"GLFW/src/init.c",
		"GLFW/src/input.c",
		"GLFW/src/monitor.c",
		"GLFW/src/vulkan.c",
		"GLFW/src/window.c"
  }

  filter "system:macosx"
    systemversion "latest"
    staticruntime "On"

    files {
      "GLFW/src/cocoa_joystic.h",
      "GLFW/src/cocoa_platform.h",
      "GLFW/src/egl_context.h",
      "GLFW/src/internal.h",
      "GLFW/src/mappings.h",
      "GLFW/src/nsgl_context.h",
      "GLFW/src/osmesa_context.h",
      "GLFW/src/posix_thread.h",

      "GLFW/src/cocoa_platform.h",
      "GLFW/src/cocoa_joystick.h",
      "GLFW/src/posix_thread.h",
      "GLFW/src/nsgl_context.h",
      "GLFW/src/egl_context.h",
      "GLFW/src/osmesa_context.h",
      "GLFW/src/cocoa_init.m",
      "GLFW/src/cocoa_joystick.m",
      "GLFW/src/cocoa_monitor.m",
      "GLFW/src/cocoa_window.m",
      "GLFW/src/cocoa_time.c",
      "GLFW/src/posix_thread.c",
      "GLFW/src/nsgl_context.m",
      "GLFW/src/egl_context.c",
      'GLFW/src/osmesa_context.c'
    }

    defines {
      "_GLFW_COCOA",
    }

	filter "configurations:Debug"
  runtime "Debug"
  symbols "on"

  filter "configurations:Release"
  runtime "Release"
  optimize "on"