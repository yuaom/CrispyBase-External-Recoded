#include "Memory.h"

HWND Memory::hwnd = NULL;
HANDLE Memory::handle = NULL;
DWORD Memory::pid = 0;
DWORD Memory::clientModule = 0;
DWORD Memory::engineModule = 0;

bool Memory::Initialize()
{
	hwnd = FindWindowA(NULL, (LPCSTR)"Counter-Strike: Global Offensive");

	if (!hwnd)
	{
		std::cout << "[-] Error failed to find CSGO!" << std::endl;
		return false;
	}

	GetWindowThreadProcessId(hwnd, &pid);

	if (pid == 0 || pid == -1)
	{
		std::cout << "[-] Error failed to grab Process ID!" << std::endl;
		return false;
	}

	handle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);

	if (!handle)
	{
		std::cout << "[-] Error failed to attach to CSGO!" << std::endl;
		return false;
	}

	std::cout << "[+] Memory initialized successfully!";

	clientModule = GetModuleBase((char*)"client_panorama.dll");
	engineModule = GetModuleBase((char*)"engine.dll");

	return true;
}

void Memory::Unload()
{
	CloseHandle(handle);
	exit(-1);
}

DWORD Memory::GetModuleBase(char* module)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
	MODULEENTRY32 mEntry;
	mEntry.dwSize = sizeof(mEntry);

	do {
		if (!strcmp(mEntry.szModule, (LPSTR)module)) {
			CloseHandle(hSnapshot);
			return (DWORD)mEntry.modBaseAddr;
		}
	} while (Module32Next(hSnapshot, &mEntry));

	CloseHandle(hSnapshot);
	return NULL;
}
