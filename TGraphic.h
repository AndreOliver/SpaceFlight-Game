#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class TGraphic
{
public:

	TGraphic(void)
	{
	}

	virtual void update(sf::Time elapsed)=0;
	virtual void draw(sf::RenderWindow & displayWindow)=0;	


	virtual ~TGraphic(void)
	{
	}

	static sf::Color randColor()
	{
		return sf::Color(rand()%256,rand()%256,rand()%256,255);
	}

};

