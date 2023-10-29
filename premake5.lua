workspace "KaryaTulisIlmiah"
	architecture "x64"
	configurations { "Debug", "Release" }
	startproject "Example"

	outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	includeDir = {}
	includeDir["SFML"] = "../External/Dependencies/include/SFML"
	includeDir["PhysicsEngine"] = "../PhysicsEngine/include"

	libDir = {}
	libDir["SFMLD"] = "../External/Dependencies/lib/SFML/sfml-debug"
	libDir["SFMLND"] = "../External/Dependencies/lib/SFML/sfml-ndebug"

	include "Example"
	include "PhysicsEngine"
