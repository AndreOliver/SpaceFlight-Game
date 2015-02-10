#pragma once
#include "tsprite.h"

class ShipSprite :
	public TSprite
{
public:

	ShipSprite(sf::Texture & texture)
	{
		setPosition(sf::Vector2f((float)-(rand()%200+100),(float)-(rand()%200+100)));
		setSpeed(sf::Vector2f((float)(rand()%200+20),(float)(rand()%200+20)));
		setAcceleration(sf::Vector2f((float)(rand()%30-10),(float)(rand()%30-10)));
		setTexture(texture);
		setColor(TGraphic::randColor());
		baseSprite.setScale(sf::Vector2f(0.5f,0.5f));
		bounce=true;
		rotation=0;
		rotationSpeed=0;
		rotationAcceleration=0;
	}

	virtual void update(sf::Time elapsed)
	{
		position.x+=rand()%5-rand()%5;
		switch(state)
		{
		case 0:
			if(rand()%300 == 0)
			{
				rotationSpeed=108000.0;
				state=1;
			}
			break;
		case 1:
			if(rand()%300 == 0)
			{
				rotationSpeed=0;
				speed=sf::Vector2f(0,0);
				state=2;
			}
			break;
		case 2:
			if(rand()%300 == 0)
			{
				rotationSpeed=0;
				state=0;
				speed=sf::Vector2f(rand()*300,rand()%300);
			}
			break;
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			setSpeed(sf::Vector2f((float)(0),(float)(0)));
			setPosition(sf::Vector2f((float)-(800),(float)-(800)));
		}

		TSprite::update(elapsed);
		}


	virtual ~ShipSprite(void)
	{
	}
};
