#pragma once
#include "tsprite.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class BackgroundSprite :
	public TSprite
{
public:

	BackgroundSprite(sf::Texture & texture)
	{
		setPosition(sf::Vector2f((float)400,(float)200));
		setTexture(texture);
		bounce=true;

	}
	
		virtual void update(sf::Time elapsed)
	{

		position.x+=rand()%3-rand()%3;
		position.y+=rand()%3-rand()%3;
		TSprite::update(elapsed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			position.y += 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			position.y -= 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			position.x += 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			position.x -=2;
		}
	}
	virtual ~BackgroundSprite(void)
	{
	}
};

