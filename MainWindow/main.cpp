#include<Windows.h>

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

	HWND hwnd = CreateWindowEx
	(
		NULL,  //exStyles
		g_sz_MY_WINDOW_CLASS, //Class name
		g_sz_MY_WINDOW_CLASS, // Windows title
		WS_OVERLAPPEDWINDOW,  //Window style
		CW_USEDEFAULT, CW_USEDEFAULT, //Window position
		CW_USEDEFAULT, CW_USEDEFAULT, // Window size
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