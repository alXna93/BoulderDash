// Project Includes
#include "Wall.h"
#include "Framework/AssetManager.h"

Wall::Wall()
	: GridObject()

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/wall2.png"));
	m_blocksMovement = true;
}