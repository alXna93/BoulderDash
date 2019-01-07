// Project Includes
#include "Diamond.h"
#include "Framework/AssetManager.h"
#include "Player.h"
#include "Level.h"
#include "GridObject.h"


Diamond::Diamond()

	: GridObject()
	
{
	
	m_sprite.setTexture(AssetManager::GetTexture("graphics/gem.png"));
	m_blocksMovement = true;
}

void Diamond::Update(sf::Time _frameTime)
{

	timeSinceFall += _frameTime.asSeconds();

	if (timeSinceFall >= 0.75f)
	{

		bool fallSuccesful = AttemptFall(sf::Vector2i(0, 1));
		timeSinceFall = 0;
	}

}

bool Diamond::AttemptFall(sf::Vector2i _direction)
{
	//Attempting to move in given direction

	//Get current position
	//Calculate target position
	sf::Vector2i targetPos = m_gridPosition + _direction;


	//TODO: Check if the space is empty
	//get list of objects in our target postion
	std::vector<GridObject*> targetCellContents = m_level->GetObjectAt(targetPos);

	//Go thru list and see if any objects block movement
	bool blocked = false;
	GridObject* blocker = nullptr;

	for (int i = 0; i < targetCellContents.size(); ++i)
	{
		if (targetCellContents[i]->getBlocksMovement() == true)
		{
			blocked = true;
			blocker = targetCellContents[i];
		}

	}


	//if empty, move there

	if (blocked == false)
	{
		return m_level->MoveObjectTo(this, targetPos);
	}

	else
	{
		Player* player = dynamic_cast<Player*>(blocker);
		if (player != nullptr)
		{
			if (_direction == sf::Vector2i(0, 1))
			{
				player->Kill();
				return false;
			}

			{
				return m_level->MoveObjectTo(this, targetPos);
			}

		}
	}
	//If movement is blocked. do nothing, return false
	return false;
}

