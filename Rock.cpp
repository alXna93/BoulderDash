// Project Includes
#include "Rock.h"
#include "Framework/AssetManager.h"
#include "GridObject.h"
#include "Level.h"
#include "Player.h"


Rock::Rock()
	: GridObject()

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/rock1.png"));
	m_blocksMovement = true;
	timeSinceFall;
	
}

void Rock::Update(sf::Time _frameTime)
{
	

	timeSinceFall += _frameTime.asSeconds();

	if (timeSinceFall >= 0.75f)
	{

		bool fallSuccesful = AttemptFall(sf::Vector2i(0, 1));
		timeSinceFall = 0;
	}
	
}

bool Rock::AttemptPush(sf::Vector2i _direction)
{
	//Attempt to move box in given direction


	//Get current position
	//Calculate target position
	sf::Vector2i targetPos = m_gridPosition + _direction;

	//check if space is empty
	//get list of objects in our target postion
	std::vector<GridObject*> targetCellContents = m_level->GetObjectAt(targetPos);
	bool blocked = false;
	GridObject* blocker = nullptr;

	
	for (int i = 0; i < targetCellContents.size(); ++i)
	{
		if (targetCellContents[i]->getBlocksMovement() == true)
		{
			blocked = true;
		}
	}

	//if empty, move there

	if (blocked == false)
	{

		bool moveSuccessful = m_level->MoveObjectTo(this, targetPos);
		return moveSuccessful;
	}

	//If movement is blocked. do nothing, return false
	return false;
}

bool Rock::AttemptFall(sf::Vector2i _direction)
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
	//if nothing under rock, fall
	if (blocked == false)
	{
		return m_level->MoveObjectTo(this, targetPos);
	}

	else
	{
		//if rock falls on player, kill the player 
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
		//Make rocks slide off each other
		Rock* rock = dynamic_cast<Rock*>(blocker);
		if (rock != nullptr)
		{
			if (_direction == sf::Vector2i(0, 1))
			{
				bool fallSuccesful = AttemptFall(sf::Vector2i(1, 1));
				return false;
			}

			if (_direction == sf::Vector2i(1, 1))
			{
				bool fallSuccesful = AttemptFall(sf::Vector2i(-1, 1));
				return false;
			}

			if (_direction == sf::Vector2i(-1, 1))
			{
				return false;
			}


		}
	
	}
	//If movement is blocked. do nothing, return false
	return false;
}

	
