#include "MainWindow.h"

#define MY_WINDOW_SETTING (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)

bool Emulator::MainWindow::MakeWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	TCHAR      szAppName[] = TEXT("FamicomEmulator");
	HWND       hWindow;
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = MainWindow::WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL; // LoadIcon(hInst, (LPCTSTR)IDI_ICON1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szAppName;
	wc.hIconSm = NULL; // LoadIcon(hInst, (LPCTSTR)IDI_ICON1);

	if (RegisterClassEx(&wc) == 0)
		return 0;

	// ウィンドウの大きさを厳密に決定する
	RECT rectWindow;
	rectWindow.top = 0;
	rectWindow.left = 0;
	rectWindow.right = 240;
	rectWindow.bottom = 240;
	AdjustWindowRect(&rectWindow, MY_WINDOW_SETTING, FALSE);
	rectWindow.right = rectWindow.right - rectWindow.left;
	rectWindow.bottom = rectWindow.bottom - rectWindow.top;
	rectWindow.top = 0;
	rectWindow.left = 0;

	RECT rect;
	rect.top = CW_USEDEFAULT;
	rect.left = CW_USEDEFAULT;
	rect.right = rectWindow.right;
	rect.bottom = rectWindow.bottom;

	hWindow = CreateWindow(szAppName, szAppName,
		MY_WINDOW_SETTING,
		rect.left, rect.top, rect.right, rect.bottom,
		NULL, NULL, hInstance, NULL);
	if (hWindow == NULL)
	{
		return false;
	}

	ShowWindow(hWindow, nShowCmd);
	UpdateWindow(hWindow);

	return true;
}

int Emulator::MainWindow::Process()
{
	//メッセージループ
	MSG msg;
	do
	{
		//メイン処理
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//アプリ側のメイン処理（１フレームあたりの処理）
		}

	} while (msg.message != WM_QUIT);

	return static_cast<int>(msg.wParam);
}

LRESULT Emulator::MainWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}