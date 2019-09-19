#pragma once
#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

#include "Memory.h"
#include "Offsets.h"
#include "SDK Structs.h"

class EntityStruct
{
public:
	DWORD address;
	SDKEntity entity;

	EntityStruct(DWORD addy, SDKEntity ent)
	{
		address = addy;
		entity = ent;
	}
	EntityStruct()
	{

	}
};

#include "Localplayer.h"
#include "Entity.h"
#include "Engine.h"