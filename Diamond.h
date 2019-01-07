#pragma once


// Project Includes
#include "GridObject.h"


//Library includes
#include <SFML/Audio.hpp>

class Diamond : public GridObject
{

public:

	Diamond();
	virtual void Update(sf::Time _frameTime);


private:

	bool AttemptFall(sf::Vector2i _direction);


};