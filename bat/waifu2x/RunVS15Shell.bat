set CurrDir=%~dp0
set VS_VER="14.0"
for /f "skip=2 tokens=1,2*" %%A in ('REG query "HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Microsoft\VisualStudio\SxS\VS7" /v %VS_VER% 2^>nul') DO set VS140PATH=%%C
cd /d "%VS140PATH%VC"
start vcvarsall.bat amd64