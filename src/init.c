#include "../SDL/include/SDL.h"
#include "defs.h"
#include <string.h>
#include <stdio.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;

SDL_Surface *image;
SDL_Texture *texture;
SDL_Rect rect;
int angle = 0;

void loadImages();

void initSDL() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
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

        rect.w = 200;
        rect.h = 200;

        rect.x = (SCREEN_WIDTH / 2) - rect.w/2;
        rect.y = (SCREEN_HEIGHT / 2) - rect.h/2;

        angle++;

        SDL_RenderCopyEx(renderer, texture, NULL, &rect, angle, NULL, SDL_FLIP_NONE);
        printf("%s",SDL_GetError());
        SDL_RenderPresent(renderer);
}

void input() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            destroyWindow();
        }
    }
}