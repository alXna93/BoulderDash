#pragma once

// Project Includes
#include "GridObject.h"
#include "Player.h"

class Exit : public GridObject
{
public:
	Exit();



private:

	Player* m_player;
};