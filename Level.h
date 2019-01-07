#pragma once

// Project Includes
#include "GridObject.h"

// Library Includes
#include <SFML/Graphics.hpp>

class Level
{

public:

	Level();

	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	void Input(sf::Event _gameEvent);
	
	void LoadLevel(int _levelToLoad);
	void ReloadLevel();
	void LoadNextLevel();
	bool CheckCompleted();
	bool IsDoorOpen();
	float GetCellSize();
	bool MoveObjectTo(GridObject* _toMove, sf::Vector2i _targetPos);
	std::vector< GridObject* > GetObjectAt(sf::Vector2i _targetPos);
	bool DeleteObjectAt(GridObject* _toDelete);

private:

	const float m_cellSize;
	int m_currentLevel;
	std::vector< std::vector< sf::Sprite > > m_background;
	std::vector< std::vector< std::vector< GridObject* > > > m_contents;
	std::vector< std::vector< std::vector< GridObject* > > > m_dirt;
	bool m_doorOpen;




};