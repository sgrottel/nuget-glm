# OpenGL Mathematics (GLM) NuGet #

![GLM Icon](./logo.png)

This repository contains all files and information to create a NuGet package out of the official GLM release.

For problems with the NuGet package contact SGrottel: 

* https://www.nuget.org/packages/glm/
* https://github.com/sgrottel/nuget-glm
* https://go.grottel.net/nuget-project/glm
* https://www.sgrottel.de
* https://go.grottel.net/nuget/glm

For problems with the library itself contact the authors:

* https://glm.g-truc.net

## GLM ##

[OpenGL Mathematics (GLM)](https://glm.g-truc.net) is a header only C++ mathematics library for graphics software based on the OpenGL Shading Language (GLSL) specifications.

GLM provides classes and functions designed and implemented with the same naming conventions and functionalities than GLSL so that anyone who knows GLSL, can use GLM as well in C++.

This project isn't limited to GLSL features. An extension system, based on the GLSL extension conventions, provides extended capabilities: matrix transformations, quaternions, data packing, random numbers, noise, etc...

The source code and the documentation, including this manual, are licensed under [the Happy Bunny License (Modified MIT) or the MIT License](https://glm.g-truc.net/copying.txt).

Project Website: https://glm.g-truc.net

## How do I get set up? ##

* Update the glm submodule to the newest release tag commit
* Install nuget command line tool.
* Run: `make_nuget.ps1 5`
	* You can specify a build number (fourth number of the version number) as argument
