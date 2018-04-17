// CmdLinePrinter.cpp - by Yuki (yukiho5048@naver.com)
//

#include <stdio.h>
#include <Windows.h>

int main(int argc, char* argv[])
{
	HWND hWnd = GetConsoleWindow();
	char CmdLine[MAX_PATH] = "";
	for (int i = 1; i < argc; i++)
		strcat(CmdLine, argv[i]);
	if (hWnd == NULL || ShowWindow(hWnd, SW_SHOW) == 0) {
		ShellExecuteA(NULL, "open", argv[0], CmdLine, NULL, SW_SHOW);
	}

	printf("Argument Count: %d\n", argc);

	for (int i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);

	system("pause");
	return 0;
}