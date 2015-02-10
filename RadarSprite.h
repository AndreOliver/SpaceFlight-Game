#pragma once
#include "tsprite.h"

class RadarSprite :
	public TSprite
{
public:

	RadarSprite(sf::Texture & texture)
	{
		setPosition(sf::Vector2f((float)(400),(float)(400)));
		setSpeed(sf::Vector2f((float)(400),(float)(0)));
		setTexture(texture);
		
		
	}
	virtual void update(sf::Time elapsed)
	{
		speed+=acceleration*elapsed.asSeconds();
		position+=speed*elapsed.asSeconds();

	
			if(position.x>pWindow->getSize().x)
			{
				baseSprite.scale(-1.f,1.f);
				speed.x = abs( speed.x )*-1;
			}
			if(position.x<0)
			{
				baseSprite.scale(-1.f,1.f);
				speed.x = abs( speed.x );
			}

		baseSprite.setPosition(position);

		rotation+=rotationSpeed*elapsed.asSeconds();
		rotationSpeed+=rotationAcceleration*elapsed.asSeconds();

		baseSprite.setRotation(rotation);
		
	}

	virtual ~RadarSprite(void)
	{
	}
};