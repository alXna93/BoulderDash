#pragma once

// Project Includes
#include "GridObject.h"
#include "Player.h"

class Pickup : public SpriteObject
{
public:

	Pickup();

	// Overriding Methods
	void Collide(GameObject& _collider);

private:

	virtual void OnPickup(Player& _player);

};