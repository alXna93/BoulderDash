
// Project Includes
#include "Exit.h"
#include "Framework/AssetManager.h"

Exit::Exit()
	: GridObject() // Initialise parent class
	, m_player(nullptr)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/door1.jpg"));
	m_blocksMovement = true;
}

//void Exit::Update(sf::Time _frameTime)
//{
//	if (m_player != nullptr)
//	{
//		bool hasKey = m_player->HasKey();
//		if (hasKey == true)
//		{
//			m_sprite.setTexture(AssetManager::GetTexture("graphics/DoorOpen.png"));
//		}
//	}
//}
