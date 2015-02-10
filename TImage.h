#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
using namespace std;

class TImage
{
public:

	TImage(int width,int height)
	{
		imageMade=false;
		iWidth=width;
		iHeight=height;
		pixelArray=new sf::Color[iWidth*iHeight];
	}

	inline void setPixel(int x,int y,unsigned char r,unsigned char g,unsigned char b,unsigned char a)
	{
		sf::Color color;
		unsigned int arrayIndex=((x*iHeight)+(y));
		color.r=r;
		color.g=g;
		color.b=b;
		color.a=a;
		pixelArray[arrayIndex]=color;
	}

	inline void setPixel(int x,int y,sf::Color color)
	{
		unsigned int arrayIndex=((x*iHeight)+(y));
		pixelArray[arrayIndex]=color;
	}

	inline void makeImage()
	{
		image.create(iWidth, iHeight,(unsigned char *) pixelArray);
		imageMade=true;
	}

	inline sf::Image * getImagePtr()
	{
		if(!imageMade) makeImage();
		return &image;
	}

	inline void saveToFile(string filename)
	{
		if(!imageMade) makeImage();
		image.saveToFile(filename);
	}


	virtual ~TImage(void)
	{
		delete[] pixelArray;
	}


private:
	int iWidth;
	int iHeight;
	sf::Color * pixelArray;
	sf::Image image;
	bool imageMade;
};

