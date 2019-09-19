#pragma once
#include "Includes.h"

class Memory;

class Vector3
{
public:
	float x = 0, y = 0, z = 0;
	Vector3(float xi, float yi, float zi)
	{
		x = xi;
		y = yi;
		z = zi;
	}
	Vector3()
	{

	}
};

class Vector2
{
public:
	float x = 0, y = 0;
	Vector2(float xi, float yi)
	{
		x = xi;
		y = yi;
	}
	Vector2()
	{

	}
};

class SDKEntity
{
public:
	char pad_0x0000[0xF4]; //0x0000
	__int32 Team; //0x00F4 
	char pad_0x00F8[0x8]; //0x00F8
	__int32 Health; //0x0100 
	__int32 Flags; //0x0104 
	char pad_0x0108[0x30]; //0x0108
	Vector3 Position; //0x0138 
	char pad_0x0144[0x7F9]; //0x0144
	__int32 Spotted; //0x093D 
	char pad_0x0941[0x1D67]; //0x0941
	DWORD BoneMatrix; //0x26A8 
	char pad_0x26AC[0xC80]; //0x26AC
	__int32 FOV; //0x332C 
	char pad_0x3330[0x44]; //0x3330
	__int32 ObserveMode; //0x3374 
	char pad_0x3378[0x598]; //0x3378
	unsigned char Scoping; //0x3910 
	char pad_0x3911[0x7]; //0x3911
	unsigned char isDefusing; //0x3918 
	char pad_0x3919[0x13]; //0x3919
	unsigned char isImmune; //0x392C 
	char pad_0x392D[0x6AC3]; //0x392D
	float MaxFlashAlpha; //0xA3F0 
	char pad_0xA3F4[0x18]; //0xA3F4
	__int32 GlowIndex; //0xA40C 
	char pad_0xA410[0xF40]; //0xA410
	unsigned char hasDefuser; //0xB350 
	char pad_0xB351[0x5B]; //0xB351
	__int32 CrosshairIndex; //0xB3AC 
	char pad_0xB3B0[0x490]; //0xB3B0

	SDKEntity()
	{

	}
}; //Size: 0xC172

class SDKEngine
{
public:
	char pad_0000[264]; //0x0000
	int32_t State; //0x0108
	char pad_010C[384]; //0x010C
	char MapName[16]; //0x028C
	char pad_029C[248]; //0x029C
	int32_t MaxPlayers; //0x0394
	char pad_0398[18928]; //0x0398
	Vector2 ViewAngles; //0x4D88
}; //Size: 0x5050