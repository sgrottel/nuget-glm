# OpenGL Mathematics (GLM) NuGet #

![GLM Icon](https://bitbucket.org/sgrottel_nuget/glm/raw/556498f4caa1806a663926db247e032f1828f734/logo.png)

This repository contains all files and information to create a NuGet package out of the officiel release of GLM.

For problems with the NuGet package contact SGrottel: 

* https://www.nuget.org/packages/glm/
* https://bitbucket.org/sgrottel_nuget/glm
* http://go.sgrottel.de/nuget-project/glm
* https://www.sgrottel.de
* http://go.sgrottel.de/nuget/glm

For problems with the library itself contact the authors:

* https://glm.g-truc.net

## GLM ##

[OpenGL Mathematics (GLM)](https://glm.g-truc.net) is a header only C++ mathematics library for graphics software based on the OpenGL Shading Language (GLSL) specifications.

GLM provides classes and functions designed and implemented with the same naming conventions and functionalities than GLSL so that anyone who knows GLSL, can use GLM as well in C++.

This project isn't limited to GLSL features. An extension system, based on the GLSL extension conventions, provides extended capabilities: matrix transformations, quaternions, data packing, random numbers, noise, etc...

The source code and the documentation, including this manual, are licensed under [the Happy Bunny License (Modified MIT) or the MIT License](https://glm.g-truc.net/copying.txt).

Project Website: https://glm.g-truc.net

## How do I get set up? ##

### Update Source ###

* Download the most current version of glm. E.g., download the zip file.
* Extract the contained directories `doc` and `glm` into this directory.
    * Note: only the `glm` and `doc/api` directory will be part of the package.

### Building the NuGet Package ###

* Install nuget command line tool.
* Run: `make_nuget.ps1 5`
* The first argument is this project directory.
* The second argument is the build number, which is to be increased each time a new package for the same version is published.
