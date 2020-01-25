#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "paintboard.h"

void v3board(int nr_lines, bool color, SDL_Renderer *renderer)
{
    for(int i = 0; i < nr_lines; ++i)
    {
        if(color)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        }

        for(int i = 0; i < nr_lines; ++i)
        {
            SDL_RenderDrawLine(renderer, 100, (100+i*133.3333), 500, (100+i*133.3333));
            SDL_RenderDrawLine(renderer, (100+i*133.3333), 100, (100+i*133.3333), 500);
        }
    }
}

void v5board(int nr_lines, bool color, SDL_Renderer *renderer)
{
    for(int i = 0; i < nr_lines; ++i)
    {
        if(color)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        }

        for(int i = 0; i < nr_lines; ++i)
        {
            SDL_RenderDrawLine(renderer, 100, (100+i*20), 500, (100+i*20));
            SDL_RenderDrawLine(renderer, (100+i*20), 100, (100+i*20), 500);
        }
    }
}

void firstLayout(SDL_Renderer *renderer){
    v3board(4, true, renderer);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
    SDL_RenderDrawLine(renderer, 133, 210, 200, 210);
}

void tabv3Prepare(int tabv3[3][3]){
    for(int a = 0;a <= 2; a++){
       for(int b = 0;b <= 2; b++){
            tabv3[b][a] = 0;
        }
    }
}

void tabv5Prepare(int tabv5[20][20]){
    int a, b;

    for( a = 0;a <= 19; a++){
       for( b = 0;b <= 19; b++){
            tabv5[b][a] = 0;
        }
    }
}

void smallLine(SDL_Renderer *renderer, int x, int y){
    SDL_SetRenderDrawColor(renderer, 0, 255, 127, 0);
    SDL_RenderDrawLine(renderer, 104+x*20, 118+20*y, 116+20*x, 118+20*y);
}

void smallBlackLine(SDL_Renderer *renderer, int x, int y){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 104+x*20, 118+20*y, 116+20*x, 118+20*y);
}

void longLine(SDL_Renderer *renderer, int x, int y){
    SDL_SetRenderDrawColor(renderer, 0, 255, 127, 0);
    SDL_RenderDrawLine(renderer, 133+133*x, 210+133*y, 200+133*x, 210+133*y);
}

void longBlackLine(SDL_Renderer *renderer, int x, int y){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 133+133*x, 210+133*y, 200+133*x, 210+133*y);
}
