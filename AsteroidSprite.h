#pragma once
#include "tsprite.h"

class AsteroidSprite :
	public TSprite
{
public:

	AsteroidSprite(sf::Texture & texture)
	{
		setPosition(sf::Vector2f((float)-(0),(float)-(rand()%200+100)));
		setSpeed(sf::Vector2f((float)(rand()%200+100),(float)(0)));
		setAcceleration(sf::Vector2f((float)(rand()%30-10),(float)(rand()%30-10)));
		setTexture(texture);
		baseSprite.setScale(sf::Vector2f(.15f,.15f));
		bounce=true;
	}

	virtual ~AsteroidSprite(void)
	{
	}
};

