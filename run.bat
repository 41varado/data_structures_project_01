@echo off

set src= ..\src

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64

if not exist bin\ (
	mkdir bin
)

pushd bin
cl.exe -EHsc -Za -Zi -std:c++20 -fsanitize=address -DWIN32_LEAN_AND_MEAN -Femain.exe %src%\*.cpp

echo.
main.exe
popd
