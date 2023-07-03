#include "../SDL/include/SDL.h"
#include "defs.h"
#include <string.h>
#include <stdio.h>
#include "init.h"



void initSDL() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    printf("%s",SDL_GetError());
    loadImages();
    if ( !window ) {
	printf("%s",SDL_GetError());
    }

    running = 1;

}

void loadImages() {
    image = SDL_LoadBMP("../test.bmp");
    if (image == NULL) image = SDL_LoadBMP("test.bmp");
    printf("%s",SDL_GetError());
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    printf("%s",SDL_GetError());

    rect.h = 400;
    rect.w = 400;

}

void destroyWindow() {
    running = 0;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    SDL_Quit();
}

void render() {
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);

        SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, SDL_FLIP_NONE);
        printf("%s",SDL_GetError());
        SDL_RenderPresent(renderer);
}

void genParticle() {
    SDL_GetMouseState(&rect.x, &rect.y);
    rect.x -= rect.w / 2;
    rect.y -= rect.h / 2;
}

void input() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            destroyWindow();
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            held = 1;
        }
        if (event.type == SDL_MOUSEBUTTONUP) {
            held = 0;
        }
    }
    if (held) genParticle();
}