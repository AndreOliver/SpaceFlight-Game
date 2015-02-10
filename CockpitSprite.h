#pragma once
#include "tsprite.h"

class CockpitSprite :
	public TSprite
{
public:


	CockpitSprite(sf::Texture & texture)
	{
		setPosition(sf::Vector2f((float)400,(float)300));
		baseSprite.setScale(sf::Vector2f(1.35f,1.35f));
		setTexture(texture);
		bounce=true;
	}

	virtual ~CockpitSprite(void)
	{
	}
};

