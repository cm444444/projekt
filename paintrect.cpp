#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "paintrect.h"

void blackrect(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rectblack = {99, 99, 405, 405};
    SDL_RenderFillRect(renderer, &rectblack);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rectblack2 = {525, 375, 50, 50};
    SDL_RenderFillRect(renderer, &rectblack2);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rectblack3 = {600, 100, 50, 270};
    SDL_RenderFillRect(renderer, &rectblack3);
}

void tomatoBigRect(SDL_Renderer *renderer, int x, int y){
    SDL_SetRenderDrawColor(renderer, 255, 99, 71, 255); // Tomato color
    SDL_Rect rectred = {133+133*x, 133+133*y, 66, 66};
    SDL_RenderFillRect(renderer, &rectred);
}

void tomatoSmallRect(SDL_Renderer *renderer, int x, int y){
    SDL_SetRenderDrawColor(renderer, 255, 99, 71, 255); // Tomato color
    SDL_Rect rectpink = {104+20*x, 104+20*y, 13, 13};
    SDL_RenderFillRect(renderer, &rectpink);
}

void blueBigRect(SDL_Renderer *renderer, int x, int y){
    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Blue color
    SDL_Rect rectred = {133+133*x, 133+133*y, 66, 66};
    SDL_RenderFillRect(renderer, &rectred);
}

void blueSmallRect(SDL_Renderer *renderer, int x, int y){
    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Blue color
    SDL_Rect rectpink = {104+20*x, 104+20*y, 13, 13};
    SDL_RenderFillRect(renderer, &rectpink);
}
