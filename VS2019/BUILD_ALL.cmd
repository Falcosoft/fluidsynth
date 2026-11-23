@echo off
setlocal
rem Optional: run from a Developer Command Prompt for Visual Studio 2019.
where MSBuild.exe >nul 2>nul
if errorlevel 1 (
  echo Run this script from the Developer Command Prompt for VS 2019.
  echo You can also open FluidSynth.sln and build in the Visual Studio IDE.
  exit /b 1
)
pushd "%~dp0"
MSBuild.exe FluidSynth.sln /t:Build /p:Configuration=Release /p:Platform=Win32 /m /nologo
if errorlevel 1 goto failed
MSBuild.exe FluidSynth.sln /t:Build /p:Configuration=Release /p:Platform=x64 /m /nologo
if errorlevel 1 goto failed
echo.
echo Finished:
echo bin\Win32\Release\libfluidsynth-3.dll
echo bin\x64\Release\libfluidsynth-3.dll
popd
exit /b 0
:failed
echo Build failed.
popd
exit /b 1
