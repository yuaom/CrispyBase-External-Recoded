#pragma once
#include "Includes.h"

class Memory
{
private:
	static HWND hwnd;
	static HANDLE handle;
	static DWORD pid;
public:
	static DWORD clientModule;
	static DWORD engineModule;

	static bool Initialize();
	static void Unload();
	static DWORD GetModuleBase(char* module);

	template<class T>
	static void W(DWORD address, T data)
	{
		bool succeeded;
		succeeded = WriteProcessMemory(handle, (LPVOID)address, &data, sizeof(T), 0);

		if (!succeeded)
		{
			std::cout << "[-] Failed to write data to address " << address << std::endl;
		}
	}

	template<class T>
	static T R(DWORD address)
	{
		T buffer;
		bool succeeded;
		succeeded = ReadProcessMemory(handle, (LPVOID)address, &buffer, sizeof(T), 0);
		
		if (!succeeded)
		{
			std::cout << "[-] Failed to read from address " << address << std::endl;
		}

		return buffer;
	}
};

