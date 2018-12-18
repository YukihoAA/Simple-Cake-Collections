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
	
	if (hWnd == NULL || ShowWindow(hWnd, SW_SHOW) == 0) {
		WCHAR CmdLine[MAX_PATH] = L"";

		for (int i = 1; i < argc; i++) {
			wcscat_s(CmdLine, argv[i]);
			wcscat_s(CmdLine, L" ");
		}

		ShellExecuteW(NULL, L"open", argv[0], CmdLine, NULL, SW_SHOW);
		return 0;
	}

	//Switch the Console to UTF-16 mode
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	std::wcout << L"Argument Count: " << argc << std::endl;
	
	for (int i = 0; i < argc; i++)
		std::wcout << L"argv[" << i << L"]: " << argv[i] << std::endl;
	
	system("pause");
	return 0;
}