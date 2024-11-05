#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#include "resource.h"

CONST CHAR* g_VALUES[] = { "Куртка", "Костюм","Штаны", "Юбка","Кросовки" };

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hIntance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hIntance, MAKEINTRESOURCE(IDD_DIALOG), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_INITDIALOG:
		{
			HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
			SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
			HWND hList = GetDlgItem(hwnd, IDC_LIST);

			for (int i = 0; i < sizeof(g_VALUES) / sizeof(g_VALUES[0]); i++)
			{
				SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)g_VALUES[i]);
				//LB-ListBox
			}
		}
			break;
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
			case IDOK:
			{
				CONST INT SIZE = 256;
				CHAR sz_buffer[SIZE]{};
				HWND hList = GetDlgItem(hwnd, IDC_LIST);
				INT i = SendMessage(hList, LB_GETCURSEL, 0, 0);

				SendMessage(hList, LB_GETTEXT, i, (LPARAM)sz_buffer);

				CHAR sz_message[SIZE]{};

				sprintf(sz_message, "Вы выбрали категорию №%i со значением \"%s\".", i+1, sz_buffer);


				MessageBox(hwnd, sz_message, "Info", MB_OK | MB_ICONINFORMATION);  
			}
				break;
			case IDC_DELETE:
			{
				HWND hList = GetDlgItem(hwnd, IDC_LIST);
				INT i = SendMessage(hList, LB_GETCURSEL, 0, 0);
				SendMessage(hList, CB_DELETESTRING, 0, i);
			}
				break;

			case IDCANCEL:
				EndDialog(hwnd, 0);
				break;
			}
			break;
		case WM_CLOSE:
			EndDialog(hwnd, 0);
			break;
	}
	return FALSE;
}