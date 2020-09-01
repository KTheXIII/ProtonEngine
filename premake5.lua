workspace "Proton"
  architecture "x64"

  startproject "Sandbox"

  configurations {
    "Debug",
    "Release",
    "Dist"
  }

outdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

indirs = {}
indirs["GLFW"] = "Proton/vendor/GLFW/include/"
indirs["Glad"] = "Proton/vendor/Glad/include"
indirs["ImGui"] = "Proton/vendor/ImGui"

group "Denpendencies"
  include "Proton/vendor/premake5.glfw.lua"
  include "Proton/vendor/Glad"
  include "Proton/vendor/premake5.imgui.lua"

group ""

project "Proton"
  location "Proton"
  kind "SharedLib"
  language "C++"
  staticruntime "on"
  cppdialect "C++17"

  targetdir("bin/" ..outdir.. "/%{prj.name}")
  objdir("bin-int/" ..outdir.. "/%{prj.name}")

  pchheader "pnpch.h"
  pchsource "Proton/src/pnpch.cpp"

  files {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.hpp",
    "%{prj.name}/src/**.cpp"
  }

  includedirs {
    "%{prj.name}/src",
		"%{indirs.GLFW}",
		"%{indirs.Glad}",
		"%{indirs.ImGui}"
  }

  links { 
    "GLFW",
    "Glad",
    "ImGui"
  }

  filter "system:macosx"
    systemversion "latest"
    system "macosx"

    defines {
      "GL_SILENCE_DEPRECATION"
    }

    links {
      "Cocoa.framework",
      "IOKit.framework",
      "CoreVideo.framework",
      "OpenGL.framework"
    }
  
  filter "system:linux"
    system "linux"
    systemversion "latest"
    staticruntime "On"

    links {
      "pthread",
      "dl",
      "m",
      "GL",
      "X11"
    }

  filter "system:Windows"
    system "Windows"
    systemversion "latest"

    links {
      "OpenGL32.lib",
    }
   
    defines {
      "PN_PLATFORM_WINDOWS",
      "PN_BUILD_DLL",
      "GLFW_INCLUDE_NONE"
    }

    postbuildcommands {
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outdir.. "/Sandbox")
    }

  filter "configurations:Debug"
    symbols "On"

  filter "configurations:Release"
    optimize "On"

  filter "configurations:Dist"
    optimize "On"

project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"
  staticruntime "on"
  cppdialect "C++17"

  targetdir("bin/" ..outdir.. "/%{prj.name}")
  objdir("bin-int/" ..outdir.. "/%{prj.name}")

  files {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs {
    "Proton/src"
  }

  links {
    "Proton"
  }

  filter "system:macosx"
    systemversion "latest"
    system "macosx"
  
  filter "system:linux"
    system "linux"
    systemversion "latest"
    staticruntime "On"
  
  filter "system:Windows"
    system "Windows"
    systemversion "latest"

  filter "configurations:Debug"
    symbols "On"

  filter "configurations:Release"
    optimize "On"

  filter "configurations:Dist"
    optimize "On"