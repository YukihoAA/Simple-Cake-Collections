@echo off
set CMAKE=D:\cmake\bin\cmake.exe
set OpenCV=D:/opencv
set OpenCV_VER=4.1.1
cd /d %~dp0
cd out
%CMAKE% -DCMAKE_GENERATOR="Visual Studio 15 2017 Win64" -DENABLE_TESTS=ON -DOPENCV_PREFIX=%OpenCV%/build/ ..
msbuild waifu2xcpp.sln /p:Configuration=Release /p:Platform=x64 -m
cd ..
