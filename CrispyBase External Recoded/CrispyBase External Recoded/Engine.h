#pragma once
#include "Includes.h"

namespace Engine
{
	extern SDKEngine EngineClass;
	extern DWORD clientStateAddress;

	extern void Initialize();

	extern int MaxPlayers();
	extern int State();
	extern Vector2 ViewAngles();

	extern void SetViewAngles(Vector2 Angles);
};

