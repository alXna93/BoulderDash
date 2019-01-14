
#pragma once

// Project Includes
#include "GridObject.h"



class Player : public GridObject
{

public:

	Player();


	//Overriding Methods
	virtual void Input(sf::Event _gameEvent);
	virtual void Update(sf::Time _frameTime);
	void Kill();

private:

	bool AttemptMove(sf::Vector2i _direction);
	

private:

	sf::Vector2i m_pendingMove;


};