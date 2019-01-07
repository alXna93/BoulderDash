#pragma once

// Project Includes
#include "GridObject.h"
#include "Player.h"

class Exit : public GridObject
{
public:
	Exit();

	void Update(sf::Time _frameTime);

private:

	Player* m_player;


};