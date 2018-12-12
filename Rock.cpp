// Project Includes
#include "Rock.h"
#include "Framework/AssetManager.h"

Rock::Rock()
	: GridObject()

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/rock1.png"));
	m_blocksMovement = true;
}