#include<Windows.h>
#define MESSAGE_BOX
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR IpCmdLine, INT nCmdShow) {
	MessageBox
	(
#ifdef MESSAGE_BOX

		NULL,
		"Hello WinAPI!\nЭто MessageBox,детка.",
		"Заголовок окна",
		MB_YESNO | MB_ICONQUESTION
		| MB_HELP
		| MB_DEFBUTTON4
		| MB_SYSTEMMODAL
	);
	return 0;
#endif // 

}