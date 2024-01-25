param([int]$verBuild = 0)
$ErrorActionPreference = "Stop"

$header = gc([System.IO.Path]::Combine($PSScriptRoot, ".\glm\glm\detail\setup.hpp")) | Out-String

if ($header -match '(?m)^#define\s+GLM_VERSION_MAJOR\s+(\d+)\s*$') { $verMajor = $Matches[1] }
else { throw "Failed to parse major version number from header." }
if ($header -match '(?m)^#define\s+GLM_VERSION_MINOR\s+(\d+)\s*$') { $verMinor = $Matches[1] }
else { throw "Failed to parse minor version number from header." }
if ($header -match '(?m)^#define\s+GLM_VERSION_PATCH\s+(\d+)\s*$') { $verPatch = $Matches[1] }
else { throw "Failed to parse patch version number from header." }

$version = "$verMajor.$verMinor.$verPatch.$verBuild"

$nuspec = [System.IO.Path]::Combine($PSScriptRoot, ".\glm.nuspec")

$releaseNotes=""
$readmefile = [System.IO.Path]::Combine($PSScriptRoot, ".\glm\readme.md")
if (Test-Path $readmefile)
{
	$seekVer = [System.Version]::Parse("$verMajor.$verMinor.$verPatch.$verBuild")
	$readme = gc $readmefile | out-string
	($readme -split "[^#]##[^#]") | Select-String -Pattern "^Release Notes" | foreach { $_ -split "[^#]###[^#]" } | Select-String -Pattern "^\[?GLM\s+(\d[.\d]*\d)[^.\d]" | foreach { if ([System.Version]::Parse($_.Matches.Groups[1].Value) -eq $seekVer) { $releaseNotes = $_ } }
}

nuget pack $nuspec -properties "version=$version;releaseNotes=$releaseNotes"
