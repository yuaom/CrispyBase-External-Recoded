#include "Includes.h"

using namespace std;

void Bhop(SDKEntity LocalEntity)
{
	if (GetAsyncKeyState(VK_SPACE) && LocalEntity.Flags == 257)
		Localplayer::Jump();
}

int main()
{
	if (Memory::Initialize()) // Load our memory class
	{
		while (true)
		{
			Engine::Initialize();

			if (Engine::State() == 6) // If client is ingame (Less lagg / less crash chance)
			{
				//Run Features
				EntityStruct LocalPlayer = Localplayer::Get();

				Bhop(LocalPlayer.entity);
			}

			if (GetAsyncKeyState(VK_END))
				Memory::Unload();

			Sleep(1); //Make CPU take some rest
		}
	}
	else {
		cout << "[-] Failed to initialize memory!" << endl;
		getchar();
		exit(-1);
	}
}