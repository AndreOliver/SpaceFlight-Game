#include "TGame.h"


int WinMain()
{
	TGame game;

	game.setup("STML Proto Game",800,600);

	while (game.windowIsOpen())
    {
		//handle events
		game.eventHandler();
		//update
		game.update();
		//draw
		game.draw();
    }
    return 0;
}


