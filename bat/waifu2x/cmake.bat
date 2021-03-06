@echo off
set CMAKE=D:\cmake\bin\cmake.exe
set OpenCV=D:/opencv
set OpenCV_VER=4.1.2
cd /d %~dp0
rd /S /q out
mkdir out
cd out
%CMAKE% -DCMAKE_GENERATOR="Visual Studio 16 2019" -A x64 -DOPENCV_PREFIX=%OpenCV%/build/ ..
msbuild waifu2xcpp.sln /p:Configuration=Release /p:Platform=x64 -m
set OpenCV=%OpenCV:/=\%
set OpenCV_VER=%OpenCV_VER:.=%
copy %OpenCV%\build\x64\vc15\bin\opencv_world%OpenCV_VER%.dll Release\
mkdir Release\models_rgb\ && copy ..\models_rgb Release\models_rgb\
cd ..
