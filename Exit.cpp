
// Project Includes
#include "Exit.h"
#include "Framework/AssetManager.h"
#include "Level.h"


Exit::Exit()
	: GridObject() // Initialise parent class
	, m_player(nullptr)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/door1.jpg"));
	m_blocksMovement = true;
	
}

//check if all diamonds collected then change sprite
void Exit::Update(sf::Time _frameTime)
{
	if (m_level->IsDoorOpen())
	{
		m_sprite.setTexture(AssetManager::GetTexture("graphics/doorOpened.jpg"));
	}
}

