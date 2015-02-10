#pragma once
#include "tsprite.h"

class BallSprite :
	public TSprite
{
public:

	BallSprite(sf::Texture & texture)
	{
		setPosition(sf::Vector2f((float)-(rand()%200+100),(float)-(rand()%200+100)));
		setSpeed(sf::Vector2f((float)(rand()%200+20),(float)(rand()%200+20)));
		setAcceleration(sf::Vector2f((float)(rand()%30-10),(float)(rand()%30-10)));
		setTexture(texture);
		setColor(TGraphic::randColor());
		bounce=true;
	}
	virtual void update(sf::Time elapsed)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				setSpeed(sf::Vector2f((float)(0),(float)(0)));
				setPosition(sf::Vector2f((float)-(800),(float)-(800)));
			}


		TSprite::update(elapsed);
	}
	virtual ~BallSprite(void)
	{
	}
};

