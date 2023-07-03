#ifndef _INIT_H
#define _INIT_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#include "../SDL/include/SDL.h"
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;

uint8_t held;
int mousex;
int mousey;

SDL_Surface *image;
SDL_Texture *texture;
SDL_Rect rect;
int angle = 0;

void loadImages();
void genParticle();

#endif