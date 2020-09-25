#include "Emulator\MainWindow.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	Emulator::MainWindow mainWindow;

	mainWindow.MakeWindow(hInstance, hPrevInstance, lpCmdLine, nShowCmd);

	int exitCode = mainWindow.Process();

	return exitCode;
}