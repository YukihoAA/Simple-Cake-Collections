@echo off
set MP4BOX="C:\Program Files\GPAC\MP4BOX.exe"
set INV=%1
set INA=%2
set RES=%3
cd /d %~dp0
if "%RES%"=="" (
set RES=result.mp4
)
if "%INA%"=="" (
set INA=input.m4a
)
if not exist %INV% (
set INV=input.mp4
)
echo Input Video:	%INV%
echo Input Audio:	%INA%
echo Ouput File:	%RES%
%MP4BOX% %INV% -add %INA%#audio:lang=ja-JP -name 2="Audio" -name 3="Commentary" -out %RES%
