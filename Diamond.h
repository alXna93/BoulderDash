#pragma once


// Project Includes
#include "GridObject.h"



class Diamond : public GridObject
{

public:

	Diamond();
	virtual void Update(sf::Time _frameTime);


private:

	bool AttemptFall(sf::Vector2i _direction);
	float timeSinceFall;


};