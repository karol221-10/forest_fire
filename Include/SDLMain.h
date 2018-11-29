#ifndef INCLUDE_SDLMAIN_H_
#define INCLUDE_SDLMAIN_H_
#include "APoint.h"
#include <memory>
#include <SDL2/SDL.h>
using std::unique_ptr;
class SDLMain {
public:
	void init();
	void clear();
	void drawPoint(int x,int y,PType type);
	void gameLoop();
    void setResolution(int width,int height);
private:
	unique_ptr<ForestMap> map;
	SDL_Window *win = nullptr;
	SDL_Renderer* renderer = nullptr;
	function<void(int,int,PType)> func;
};
#endif
