#pragma once
#include "tgraphic.h"


class TSprite :
	public TGraphic
{
public:
	friend class TGame;
	TSprite(void)
	{
		pWindow=NULL;	
		rotation=0;
		rotationSpeed=0;
		rotationAcceleration=0;
		bounce=true;
		state=0;
	}

	void setWindowPtr(sf::RenderWindow *  pWin)
	{
		pWindow=pWin;
	}

	void setColor(sf::Color c)
	{
		baseSprite.setColor(c);
	}
	
	void setTexture(sf::Texture & texture)
	{
		baseSprite.setTexture(texture);
		sf::Vector2u textureSize = texture.getSize();
		baseSprite.setOrigin(textureSize.x/2.0f,textureSize.y/2.0f);
	}
	
	void setPosition(sf::Vector2f p)
	{
		position=p;
	}

	void setSpeed(sf::Vector2f s)
	{
		speed=s;
	}

	void setAcceleration(sf::Vector2f a)
	{
		acceleration=a;
	}

	virtual void update(sf::Time elapsed)
	{
		speed+=acceleration*elapsed.asSeconds();
		position+=speed*elapsed.asSeconds();

		if(bounce)
		{
			if(position.x>pWindow->getSize().x) speed.x=abs(speed.x)*-1;


			sf::Vector2u wSize = pWindow->getSize();

			if( position.y > wSize.y  ) speed.y = abs( speed.y )*-1;
			
			if(position.x<0) speed.x=abs(speed.x);
			
			if(position.y<0) speed.y=abs(speed.y);
		}



		baseSprite.setPosition(position);

		rotation+=rotationSpeed*elapsed.asSeconds();
		rotationSpeed+=rotationAcceleration*elapsed.asSeconds();

		baseSprite.setRotation(rotation);


	}

	virtual void draw(sf::RenderWindow & displayWindow)
	{
		displayWindow.draw(baseSprite);
	}

	virtual ~TSprite(void)
	{
	}

protected:
	sf::Sprite baseSprite;
	sf::Vector2f position;
	sf::Vector2f speed;
	sf::Vector2f acceleration;
	sf::Vector2f scale;
	float rotation;
	float rotationSpeed;
	float rotationAcceleration;
	bool bounce;
	int state;
	sf::RenderWindow *  pWindow;
};

