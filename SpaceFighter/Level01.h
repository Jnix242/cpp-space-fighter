#pragma once

#include "Level.h"
#include "PlayerShip.h"

/** @brief The first level of the game. */
class Level01 :	public Level
{
private:
	

public:
	
	/** @brief Instantiate a level object. */
	Level01() { }
	virtual ~Level01() { }

	/** @brief Load the content for the level, including game objects and resources.
		@param resourceManager A reference to the game's resource manager,
		used for loading and managing game assets (resources). */
	virtual void LoadContent(ResourceManager& resourceManager);
};

