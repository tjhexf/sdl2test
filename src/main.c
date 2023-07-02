#include <stdio.h>
#include <stdbool.h>
#include "../SDL/include/SDL.h"
#include "init.h"


int running;

int main(int argc, char *argv[]) {
    initSDL();
    while (running) {        
        input();
        render();
    }
}