#include "Entity.h"

EntityStruct Entity::GetEntity(int id)
{
	DWORD entityAddress = Memory::R<DWORD>(Memory::clientModule + Offsets::dwEntityList + (id * 0x10));
	SDKEntity entity = Memory::R<SDKEntity>(entityAddress);

	EntityStruct retValue = EntityStruct(entityAddress, entity);

	return retValue;
}

void Entity::SetSpotted(DWORD address, bool value)
{
	Memory::W<bool>(address + Offsets::m_bSpotted, value);
}
