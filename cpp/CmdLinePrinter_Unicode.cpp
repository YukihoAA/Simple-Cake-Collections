// CmdLinePrinter_Unicode.cpp - by Yuki (yukiho5048@naver.com)
//

#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

int wmain(void)
{
	int argc = 0;
	LPWSTR *argv = CommandLineToArgvW(GetCommandLine(), &argc);
	HWND hWnd = GetConsoleWindow();

	//Switch the Console to UTF-16 mode
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	std::wcout << L"Argument Count: " << argc << std::endl;
	
	for (int i = 0; i < argc; i++)
		std::wcout << L"argv[" << i << L"]: " << argv[i] << std::endl;
	
	system("pause");
	return 0;
}