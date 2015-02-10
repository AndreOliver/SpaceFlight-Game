#pragma once
#include "tsprite.h"

class MinionConfusedSprite :
	public TSprite
{
public:

	MinionConfusedSprite(sf::Texture & texture)
	{
		setPosition(sf::Vector2f((float)-(0),(float)-(rand()%200+100)));
		setSpeed(sf::Vector2f((float)(rand()%200+100),(float)(0)));
		setAcceleration(sf::Vector2f((float)(rand()%30-10),(float)(rand()%30-10)));
		setTexture(texture);
		baseSprite.setScale(sf::Vector2f(.75f,.75f));
		bounce=true;
	}

virtual void update(sf::Time elapsed)
	{
	if(rand()%208 == 0)
	{
		setSpeed(sf::Vector2f((float)(-rand()%400),(float)(-rand()%400)));
	}
	else if(rand()%208 == 1)
	{
		rotationSpeed = 150;
	}
	else if(rand()%208 == 2)
	{
		setSpeed(sf::Vector2f((float)(-rand()%400),(float)(rand()%400)));
	}
	else if(rand()%208 == 3)
	{
		rotationSpeed = -150;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			setSpeed(sf::Vector2f((float)(0),(float)(0)));
			setPosition(sf::Vector2f((float)-(800),(float)-(800)));
		}


		TSprite::update(elapsed);
	}

	virtual ~MinionConfusedSprite(void)
	{
	}
};

