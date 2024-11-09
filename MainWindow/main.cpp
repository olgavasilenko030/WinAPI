#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>
#include<cstdio>

CONST CHAR g_sz_MY_WINDOW_CLASS[] = "My window";//��� ������ ����

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hIstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	// 1) ����������� ������ ����
	WNDCLASSEX wc;
	ZeroMemory (&wc, sizeof(wc));
	wc.style = 0;
	wc.cbSize = sizeof(wc);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0; //cd- Count Bytes

	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;

	wc.hInstance = hIstance;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_sz_MY_WINDOW_CLASS;
	wc.lpfnWndProc = (WNDPROC)WndProc;

	if (!RegisterClassEx(&wc)) 
	{
		MessageBox(NULL, "Class registration failed", NULL, MB_OK | MB_ICONINFORMATION);
		return 0;
	}

	//2) �������� ����:


	INT screen_width = GetSystemMetrics(SM_CXSCREEN);
	INT screen_height = GetSystemMetrics(SM_CYSCREEN);//���������� ������

	INT window_width = screen_width * 3 / 4;
	INT window_height = screen_height * 0.75;
	INT window_start_x = screen_width / 8;
	INT window_start_y = screen_height / 8;

	HWND hwnd = CreateWindowEx
	(
		NULL,  //exStyles
		g_sz_MY_WINDOW_CLASS, //Class name
		g_sz_MY_WINDOW_CLASS, // Windows title
		WS_OVERLAPPEDWINDOW,  //Window style
		window_start_x, window_start_y, //Window position
		window_width, window_height, // Window size
		NULL, // Parent Window
		NULL, // Main menu ResourceID for MainWindow or ResourceID for ChildWindow
		hIstance,
		NULL

	);
	ShowWindow(hwnd, nCmdShow); //������ ����� ����������� ���� (���������� �� ���� �����, �������� � ����, �������� � ������ �����)

	UpdateWindow(hwnd); //������������� ����


	//3) ������ ����� ���������:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}


	return msg.message;
}

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_CREATE:
		break;
	case WM_MOVE:
	case WM_SIZE:
	{
		RECT rect;
		GetWindowRect(hwnd, &rect);
		INT window_width = rect.right - rect.left;
		INT window_height = rect.bottom - rect.top;
		
		CONST INT SIZE = 256;
		CHAR sz_title[SIZE]{};
		sprintf(sz_title, "%s- Position:%ix%i;\tSize: %ix%i",g_sz_MY_WINDOW_CLASS, rect.left, rect.top,window_width,window_height);
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_title);
	}
		break;
	case WM_COMMAND:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return FALSE;
}