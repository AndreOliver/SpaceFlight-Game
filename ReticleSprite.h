#pragma once
#include "tsprite.h"

class ReticleSprite :
	public TSprite
{
public:


	ReticleSprite(sf::Texture & texture)
	{
		setPosition(sf::Vector2f((float)400,(float)275));
		baseSprite.setScale(sf::Vector2f(1.35f,1.35f));
		setTexture(texture);
		bounce=true;
	}



	virtual ~ReticleSprite(void)
	{
	}
};

