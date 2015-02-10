#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "TGraphicList.h"
#include "BallSprite.h"
#include "ShipSprite.h"
#include "BackgroundPlanet.h"
#include "CockpitSprite.h"
#include "PhotonSprite.h"
#include "ReticleSprite.h"
#include "RadarSprite.h"
#include "AsteroidSprite.h"
#include "MinionTongueSprite.h"
#include "MinionConfusedSprite.h"

class TGame
{
public:

	TGame(void)
	{
		srand((unsigned int)time(NULL));
	}

	virtual void setup(string gameName,int gameWidth, int gameHeight)
	{
		if(!backgroundTexture.loadFromFile("..\\Resources\\background.jpg"))
		{
		}
		if(!ballTexture.loadFromFile("..\\Resources\\ball02.png"))
		{
		}
		if(!shipTexture.loadFromFile("..\\Resources\\ship4.png"))
		{
		}
		if(!photonTexture.loadFromFile("..\\Resources\\photon.png"))
		{
		}
		if(!asteroidTexture.loadFromFile("..\\Resources\\asteroid.png"))
		{
		}
		if(!minionTongueTexture.loadFromFile("..\\Resources\\minionTongueNoBackground.png"))
		{
		}
		if(!minionConfusedTexture.loadFromFile("..\\Resources\\minionNoBackground.png"))
		{
		}
		if(!radarTexture.loadFromFile("..\\Resources\\radar.png"))
		{
		}
		if(!reticleTexture.loadFromFile("..\\Resources\\reticle.png"))
		{
		}
		if(!cockpitTexture.loadFromFile("..\\Resources\\cockpit.png"))
		{
		}

		sf::Font font;
		if(!font.loadFromFile("..\\Resources\\persansb.ttf"))
		{
		
		}
		




		pMainWindow = new sf::RenderWindow(sf::VideoMode(gameWidth, gameHeight), gameName);
		pMainWindow->setVerticalSyncEnabled(true);

		//adds one background image.. must be first because all other sprites should be drawn on top of it
			BackgroundSprite * pBGSprite;
			pBGSprite=new BackgroundSprite(backgroundTexture);
			pBGSprite->setWindowPtr(pMainWindow);
			pBGSprite->bounce=true;
			mainDisplayList.add(pBGSprite);
		
		for(int i=0;i<10;i++)
		{
			BallSprite * pBall;
			pBall=new BallSprite(ballTexture);
			pBall->setWindowPtr(pMainWindow);
			pBall->bounce=true;
			mainDisplayList.add(pBall);
		}

		for(int i=0;i<1;i++)
		{
			ShipSprite * pBall;
			pBall=new ShipSprite(shipTexture);
			pBall->setWindowPtr(pMainWindow);
			pBall->bounce=true;
			mainDisplayList.add(pBall);
		}
		//Photon sprite
		for(int j=0;j<5;j++)
		{
			for(int k=0;k<4;k++)
			{
			AsteroidSprite * pSprite;
			pSprite = new AsteroidSprite(asteroidTexture);
			pSprite->setWindowPtr(pMainWindow);
			pSprite->bounce=true;
			mainDisplayList.add(pSprite);
			}
			
			for(int i=0;i<10;i++)
			{
				PhotonSprite * pBall;
				pBall=new PhotonSprite(photonTexture);
				pBall->setWindowPtr(pMainWindow);
				pBall->bounce=true;
				mainDisplayList.add(pBall);
			}
			MinionTongueSprite * pSprite;
			pSprite = new MinionTongueSprite(minionTongueTexture);
			pSprite->setWindowPtr(pMainWindow);
			pSprite->bounce=true;
			mainDisplayList.add(pSprite);

			
			MinionConfusedSprite * pSprite1;
			pSprite1 = new MinionConfusedSprite(minionConfusedTexture);
			pSprite1->setWindowPtr(pMainWindow);
			pSprite->bounce=true;
			mainDisplayList.add(pSprite1);
		}
		//two radars that sweep in different directions
		for(int i=0;i<1;i++)
		{
			RadarSprite * pBall;
			pBall=new RadarSprite(radarTexture);
			pBall->setWindowPtr(pMainWindow);
			pBall->bounce=true;
			mainDisplayList.add(pBall);
		}
			
		//one cockpit image
			CockpitSprite * pCPSprit;
			pCPSprit = new CockpitSprite(cockpitTexture);
			pCPSprit->setWindowPtr(pMainWindow);
			pCPSprit->bounce=true;
			mainDisplayList.add(pCPSprit);
		//one reticle for cockpit
			ReticleSprite * pRSprite;
			pRSprite = new ReticleSprite(reticleTexture);
			pRSprite->setWindowPtr(pMainWindow);
			pRSprite->bounce=true;
			mainDisplayList.add(pRSprite);
		
		elapsedTime=gameClock.restart();
	}

	sf::RenderWindow * getPtrWindow()
	{
		return pMainWindow;
	}


	virtual void update()
	{
		elapsedTime=gameClock.restart();
		mainDisplayList.update(elapsedTime);
	}

	virtual void draw()
	{
		pMainWindow->clear();

		mainDisplayList.draw(*pMainWindow);

		pMainWindow->display();
	}


	void eventHandler()
	{
		sf::Event event;
		while (getPtrWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				getPtrWindow()->close();
		}
	}


	bool windowIsOpen()
	{
		return pMainWindow->isOpen();
	}


	virtual ~TGame(void)
	{
	}

private:

	sf::RenderWindow * pMainWindow;
	TGraphicList mainDisplayList;
	sf::Clock gameClock;
	sf::Time elapsedTime;
	sf::Texture backgroundTexture;
	sf::Texture ballTexture;
	sf::Texture shipTexture;
	sf::Texture cockpitTexture;
	sf::Texture photonTexture;
	sf::Texture reticleTexture;
	sf::Texture radarTexture;
	sf::Texture asteroidTexture;
	sf::Texture minionTongueTexture;
	sf::Texture minionConfusedTexture;
};

