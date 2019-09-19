#include "Engine.h"

SDKEngine Engine::EngineClass;
DWORD Engine::clientStateAddress;

void Engine::Initialize()
{
	clientStateAddress = Memory::R<DWORD>(Memory::engineModule + Offsets::dwClientState);
	EngineClass = Memory::R<SDKEngine>(clientStateAddress);
}

int Engine::MaxPlayers()
{
	return EngineClass.MaxPlayers;
}

int Engine::State()
{
	return EngineClass.State;
}

Vector2 Engine::ViewAngles()
{
	return EngineClass.ViewAngles;
}

void Engine::SetViewAngles(Vector2 Angles)
{
	Memory::W<Vector2>(clientStateAddress + Offsets::dwClientState_ViewAngles, Angles);
}
