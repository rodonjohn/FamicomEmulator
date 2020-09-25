#pragma once

#include <Windows.h>

namespace Utility
{
	class WindowBase
	{
	public:
		virtual bool MakeWindow();
		virtual int Process();
	};
}