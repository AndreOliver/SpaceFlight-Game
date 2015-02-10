#pragma once
#include "tsprite.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class PhotonSprite :
	public TSprite
{
public:

	PhotonSprite(sf::Texture & texture)
	{
		setPosition(sf::Vector2f((float)400,(float)200));
		setSpeed(sf::Vector2f((float)(-rand()%300+20),(float)(-rand()%300+20)));
		setAcceleration(sf::Vector2f((float)(rand()%90),(float)(rand()%90)));
		setTexture(texture);
		baseSprite.setScale(.25f,.25f);
		bounce=true;
		
	}
	
virtual void update(sf::Time elapsed)
	{
	if(rand()%32 == 0)
	{
		setSpeed(sf::Vector2f((float)(-rand()%400),(float)(-rand()%400)));
	}
	else if(rand()%32 == 1)
	{
		setSpeed(sf::Vector2f((float)(rand()%400),(float)(rand()%400)));
	}
	else if(rand()%32 == 2)
	{
		setSpeed(sf::Vector2f((float)(-rand()%400),(float)(rand()%400)));
	}
	else if(rand()%32 == 3)
	{
		setSpeed(sf::Vector2f((float)(rand()%400),(float)(-rand()%400)));
	}

		TSprite::update(elapsed);
	}
	virtual ~PhotonSprite(void)
	{
	}
};

