/*
 * SDLMain.cpp
 *
 *  Created on: 18 lis 2018
 *      Author: karol
 */
#include "SDLMain.h"
#include <functional>
#include <iostream>
void SDLMain::init() {
	win = SDL_CreateWindow("Symulator pożaru lasu",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,700,700,SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
	func = bind(&SDLMain::drawPoint,this,placeholders::_1,placeholders::_2,placeholders::_3);
	map = make_unique<ForestMap>();
}
void SDLMain::clear() {
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
}
void SDLMain::drawPoint(int x,int y,PType type) {
	switch(type) {
		case EXIST:
			SDL_SetRenderDrawColor(renderer,0,255,0,255);
		break;
		case FIRE:
			SDL_SetRenderDrawColor(renderer,255,0,0,255);
		break; 
		case BURN:
			SDL_SetRenderDrawColor(renderer, 91, 46, 0, 255);
		break;
			return;
			break;
	}
	SDL_RenderDrawPoint(renderer,x,y);
}
void SDLMain::gameLoop() {
	bool is_running = true;
	while(is_running) {
		clear();
		map->drawAll(func);
		SDL_RenderPresent(renderer);
		SDL_Delay(1000/60);
	}
}
void SDLMain::setResolution(int width,int height) {
	SDL_RenderSetLogicalSize(renderer,width,height);
	SDL_RenderSetViewport(renderer,nullptr);
}

