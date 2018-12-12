// Project Includes
#include "Player.h"
#include "Framework/AssetManager.h"
#include "Level.h"

Player::Player()
	: GridObject()
	, m_pendingMove(0, 0)

{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/player/playerStandDown.png"));
}

void Player::Input(sf::Event _gameEvent)
{
	//Read input from keyboard
	//Convert to direction to move in
	//The move player

	//Was the event a key press?
	if (_gameEvent.type == sf::Event::KeyPressed)
	{
		//Yes it was a key press!
		//What key was pressed?

		if (_gameEvent.key.code == sf::Keyboard::W)
		{
			//it was W!!
			//Move up
			m_pendingMove = sf::Vector2i(0, -1);
			m_sprite.setTexture(AssetManager::GetTexture("graphics/player/playerStandUp.png"));
		}



		else if (_gameEvent.key.code == sf::Keyboard::A)
		{
			//it was A!!
			//Move left
			m_pendingMove = sf::Vector2i(-1, -0);
			m_sprite.setTexture(AssetManager::GetTexture("graphics/player/playerStandLeft.png"));
		}


		else if (_gameEvent.key.code == sf::Keyboard::S)
		{
			//it was S!!
			//Move down
			m_pendingMove = sf::Vector2i(0, 1);
			m_sprite.setTexture(AssetManager::GetTexture("graphics/player/playerStandDown.png"));
		}

		else if (_gameEvent.key.code == sf::Keyboard::D)
		{
			//it was D!!
			//Move right
			m_pendingMove = sf::Vector2i(1, 0);
			m_sprite.setTexture(AssetManager::GetTexture("graphics/player/playerStandRight.png"));
		}

	}
}

void Player::Update(sf::Time _frameTime)
{
	// if we have movement waiting to be processed
	if (m_pendingMove.x != 0 || m_pendingMove.y != 0)
	{

		bool moveSuccessful = AttemptMove(m_pendingMove);

		if (moveSuccessful == true)
		{
			
		}

		//and clear pending movement
		m_pendingMove = sf::Vector2i(0, 0);


	}

}

bool Player::AttemptMove(sf::Vector2i _direction)
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

	for (int i = 0; i < targetCellContents.size(); ++i)
	{
		if (targetCellContents[i]->getBlocksMovement() == true)
		{
			blocked = true;
			//m_bumpSound.play();
			//blocker = targetCellContents[i];
		}

		else
		{
			m_level->DeleteObjectAt(targetCellContents[i]);
		}
	}


	//if empty, move there

	if (blocked == false)
	{
		return m_level->MoveObjectTo(this, targetPos);
	}


	//If movement is blocked. do nothing, return false
	return false;

}