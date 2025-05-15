
#include "BioEnemyShip.h"
#include "Level.h"
#include "PlayerShip.h"


BioEnemyShip::BioEnemyShip()
{
	SetSpeed(500);
	SetMaxHitPoints(1);
	SetCollisionRadius(20);
}



void BioEnemyShip::Update(const GameTime& gameTime )
{
	if (IsActive() )
	{
		
		PlayerShip* pTrack = GetCurrentLevel()->GetClosestObject<PlayerShip>(GetPosition(), 800.0f);
		
		if (pTrack)
		{
			Vector2 PlayerDirection = (pTrack->GetPosition() - GetPosition());
			float length = PlayerDirection.Length();
			if (length !=0)
			{
				PlayerDirection /= length;
			}

			SetDesiredDirection(PlayerDirection);

			std::cout << PlayerDirection.X << "," << PlayerDirection.Y;
		}

		float speed = 150.0f;
		TranslatePosition(m_desiredDirection * speed * gameTime.GetElapsedTime());

		

		if (!IsOnScreen()) Deactivate();
	}

	EnemyShip::Update(gameTime);
}


void BioEnemyShip::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}
