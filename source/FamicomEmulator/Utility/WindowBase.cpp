#include "WindowBase.h"

bool Utility::WindowBase::MakeWindow()
{
    return false;
}

int Utility::WindowBase::Process()
{
	MSG	msg;

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return static_cast<int>(msg.wParam);
}