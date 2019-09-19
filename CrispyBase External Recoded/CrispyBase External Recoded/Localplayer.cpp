#include "Localplayer.h"

EntityStruct Localplayer::Get()
{
	SDKEntity LocalEntity;
	DWORD localAddress;

	localAddress = Memory::R<DWORD>(Memory::clientModule + Offsets::dwLocalPlayer);
	LocalEntity = Memory::R<SDKEntity>(localAddress);

	EntityStruct entity = EntityStruct(localAddress, LocalEntity);

	return entity;
}

void Localplayer::SetFOV(DWORD localAddress, int FOV)
{
	Memory::W<int>(localAddress + Offsets::m_iFOV, FOV);
}

void Localplayer::SetMaxFlashAlpha(DWORD localAddress, float alpha)
{
	Memory::W<float>(localAddress + Offsets::m_flFlashMaxAlpha, alpha);
}

void Localplayer::Jump()
{
	Memory::W<int>(Memory::clientModule + Offsets::dwForceJump, 5);
	Sleep(20);
	Memory::W<int>(Memory::clientModule + Offsets::dwForceJump, 4);
}

void Localplayer::Attack()
{
	Memory::W<int>(Memory::clientModule + Offsets::dwForceAttack, 5);
	Sleep(20);
	Memory::W<int>(Memory::clientModule + Offsets::dwForceAttack, 4);
}