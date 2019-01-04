#pragma once


// Project Includes
#include "GridObject.h"

class Rock : public GridObject
{

public:

	Rock();
	virtual void Update(sf::Time _frameTime);

private: 

	bool AttemptFall(sf::Vector2i _direction);

};