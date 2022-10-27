workspace "FuzzyWuzzy"
	architecture "x64"
	configurations { "Debug", "Release" }
	startproject "FuzzyWuzzy"
	characterset "Unicode"
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "On"
		
	filter "configurations:Release"
		defines "NDEBUG"
		runtime "Release"
		optimize "On"

project "FuzzyWuzzySample"
	kind "ConsoleApp"
	language "C++"
	staticruntime "On"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files { 
		"FuzzyWuzzy/src/**.hpp",
		"FuzzyWuzzy/src/**.h",
		"FuzzyWuzzy/src/**.c",
		"FuzzyWuzzy/src/**.cpp",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp" }
	
	includedirs { 
		"%{prj.name}/src",
		"FuzzyWuzzy/src"
	}
	
	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"
