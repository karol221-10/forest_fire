#include <iostream>
#include "SDLMain.h"
using namespace std;

int main()
{
	SDLMain sdl;
	sdl.init();
	sdl.clear();
	sdl.gameLoop();
	return 0;
}
