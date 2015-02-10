#pragma once
#include "tgraphic.h"
#include <vector>
using namespace std;
class TGraphicList :
	public TGraphic
{
public:

	TGraphicList(void)
	{
	}

	virtual void update(sf::Time elapsed)
	{
		for each (TGraphic * ptg in v)
		{
			ptg->update(elapsed);
		}
	}

	virtual void draw(sf::RenderWindow & drawWindow)
	{
		for each (TGraphic *  ptg in v)
		{
			ptg->draw(drawWindow);
		}
	}

	virtual void add(TGraphic * ptg)
	{
		v.push_back(ptg);
	}

	virtual ~TGraphicList(void)
	{
	}

private:

	vector<TGraphic *> v;
};

