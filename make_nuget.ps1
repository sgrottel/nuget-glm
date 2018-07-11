param([int]$verBuild)
$ErrorActionPreference = "Stop"

$header = gc([System.IO.Path]::Combine($PSScriptRoot, ".\glm\detail\setup.hpp")) | Out-String

if ($header -match '(?m)^#define\s+GLM_VERSION_MAJOR\s+(\d+)\s*$') { $verMajor = $Matches[1] }
else { throw "Failed to parse major version number from header." }
if ($header -match '(?m)^#define\s+GLM_VERSION_MINOR\s+(\d+)\s*$') { $verMinor = $Matches[1] }
else { throw "Failed to parse minor version number from header." }
if ($header -match '(?m)^#define\s+GLM_VERSION_PATCH\s+(\d+)\s*$') { $verPatch = $Matches[1] }
else { throw "Failed to parse patch version number from header." }
if ($header -match '(?m)^#define\s+GLM_VERSION_REVISION\s+(\d+)\s*$') { $verRevision = $Matches[1] }
else { throw "Failed to parse patch version number from header." }

$verBuild = $verRevision * 100 +$verBuild
$version = "$verMajor.$verMinor.$verPatch.$verBuild"

$nuspec = [System.IO.Path]::Combine($PSScriptRoot, ".\glm.nuspec")

nuget pack $nuspec -properties version=$version
