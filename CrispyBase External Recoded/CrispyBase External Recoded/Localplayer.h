#pragma once
#include "Includes.h"

namespace Localplayer
{
	extern EntityStruct Get();

	extern void SetFOV(DWORD localAddress, int FOV);
	extern void SetMaxFlashAlpha(DWORD localAddress, float alpha);
	extern void Jump();
	extern void Attack();
};

