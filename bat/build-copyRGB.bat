@echo off
cd /d %~dp0
rd /S /q out\Release\models_rgb\
mkdir out\Release\models_rgb\ && copy models_rgb out\Release\models_rgb\