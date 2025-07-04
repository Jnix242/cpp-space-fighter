
#pragma once

#include "EnemyShip.h"
#include "PlayerShip.h"

/** @brief Represents an enemy ship that is biological in nature. */
class BioEnemyShip : public EnemyShip
{
	PlayerShip* m_pPlayer = nullptr;

public:

	/** @brief Creates a new instance of BioEnemyShip. */
	BioEnemyShip();
	virtual ~BioEnemyShip() { }

	/** @brief Sets the texture that will be used to render the enemy ship.
		@param pTexture A pointer to the texture. */
	virtual void SetTexture(Texture *pTexture) { m_pTexture = pTexture; }

	/** @brief Updates the enemy ship.
		@param gameTime A reference to the game time object. */
	virtual void Update(const GameTime& gameTime) override;

	virtual void SetDesiredDirection(const Vector2 direction) { m_desiredDirection.Set(direction); }

	

	

	/** @brief Draws the enemy ship.
		@param spriteBatch A reference to the game's sprite batch, used for rendering. */
	virtual void Draw(SpriteBatch& spriteBatch);


private:
     Vector2 m_desiredDirection;
	Texture *m_pTexture = nullptr;

}; 