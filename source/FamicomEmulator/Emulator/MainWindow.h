#pragma once

#include <Windows.h>
#include "..\Utility\WindowBase.h"

namespace Emulator
{
	class MainWindow : public Utility::WindowBase
	{
	public:
		explicit MainWindow() { }

		bool MakeWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);
		int Process();

		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}
