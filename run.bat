@echo off

set src= ..\src

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64

if not exist bin\ (
	mkdir bin
) else (
	del /s /q bin\*.*
)

pushd bin
cl.exe -EHsc -Za -Zi -fsanitize=address %src%\main.cpp

echo.
main.exe
popd