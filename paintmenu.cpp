#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

void vPeople(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 255, 140, 0, 255);
    SDL_RenderDrawLine(renderer, 535, 185, 535, 205);
    SDL_RenderDrawLine(renderer, 535, 185, 528, 192);
    SDL_RenderDrawLine(renderer, 545, 195, 549, 205);
    SDL_RenderDrawLine(renderer, 549, 205, 553, 195);
    SDL_RenderDrawLine(renderer, 565, 185, 565, 205);
    SDL_RenderDrawLine(renderer, 565, 185, 558, 192);

    SDL_SetRenderDrawColor(renderer, 173, 255, 47, 0);
    SDL_RenderDrawLine(renderer, 535, 315, 535, 335);
    SDL_RenderDrawLine(renderer, 535, 315, 528, 322);
    SDL_RenderDrawLine(renderer, 545, 325, 549, 335);
    SDL_RenderDrawLine(renderer, 549, 335, 553, 325);
    SDL_RenderDrawLine(renderer, 565, 315, 565, 335);
    SDL_RenderDrawLine(renderer, 565, 315, 558, 322);
}

void vAI(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 255, 140, 0, 255);
    SDL_RenderDrawLine(renderer, 535, 215, 535, 235);
    SDL_RenderDrawLine(renderer, 535, 215, 528, 222);
    SDL_RenderDrawLine(renderer, 545, 225, 549, 235);
    SDL_RenderDrawLine(renderer, 549, 235, 553, 225);
    SDL_RenderDrawLine(renderer, 565, 215, 585, 215);
    SDL_RenderDrawLine(renderer, 565, 230, 585, 230);
    SDL_RenderDrawLine(renderer, 565, 215, 565, 230);
    SDL_RenderDrawLine(renderer, 585, 215, 585, 230);
    SDL_RenderDrawLine(renderer, 565, 230, 560, 235);
    SDL_RenderDrawLine(renderer, 585, 230, 580, 235);
    SDL_RenderDrawLine(renderer, 580, 235, 560, 235);

    SDL_SetRenderDrawColor(renderer, 173, 255, 47, 0);
    SDL_RenderDrawLine(renderer, 535, 345, 535, 365);
    SDL_RenderDrawLine(renderer, 535, 345, 528, 352);
    SDL_RenderDrawLine(renderer, 545, 355, 549, 365);
    SDL_RenderDrawLine(renderer, 549, 365, 553, 355);
    SDL_RenderDrawLine(renderer, 565, 345, 585, 345);
    SDL_RenderDrawLine(renderer, 565, 360, 585, 360);
    SDL_RenderDrawLine(renderer, 565, 345, 565, 360);
    SDL_RenderDrawLine(renderer, 585, 345, 585, 360);
    SDL_RenderDrawLine(renderer, 565, 360, 560, 365);
    SDL_RenderDrawLine(renderer, 585, 360, 580, 365);
    SDL_RenderDrawLine(renderer, 580, 365, 560, 365);
}

void arrow(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0, 250, 154, 255); // Lime color
    SDL_RenderDrawLine(renderer, 600, 550, 630, 530);
    SDL_RenderDrawLine(renderer, 600, 550, 670, 550);
    SDL_RenderDrawLine(renderer, 600, 550, 630, 570);
}

void save(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0, 250, 154, 255); // Lime color
    SDL_RenderDrawLine(renderer, 620, 370, 655, 370);
    SDL_RenderDrawLine(renderer, 620, 420, 670, 420);
    SDL_RenderDrawLine(renderer, 620, 370, 620, 420);
    SDL_RenderDrawLine(renderer, 670, 385, 670, 420);
    SDL_RenderDrawLine(renderer, 655, 370, 670, 385);
    SDL_RenderDrawLine(renderer, 600, 395, 635, 395);
    SDL_RenderDrawLine(renderer, 635, 395, 625, 385);
    SDL_RenderDrawLine(renderer, 635, 395, 625, 405);
}

void load(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0, 250, 154, 255); // Lime color
    SDL_RenderDrawLine(renderer, 620, 450, 655, 450);
    SDL_RenderDrawLine(renderer, 620, 500, 670, 500);
    SDL_RenderDrawLine(renderer, 620, 450, 620, 500);
    SDL_RenderDrawLine(renderer, 670, 465, 670, 500);
    SDL_RenderDrawLine(renderer, 655, 450, 670, 465);
    SDL_RenderDrawLine(renderer, 600, 475, 635, 475);
    SDL_RenderDrawLine(renderer, 600, 475, 610, 465);
    SDL_RenderDrawLine(renderer, 600, 475, 610, 485);
}

int menuArrow1(SDL_Renderer *renderer, int x){
    SDL_SetRenderDrawColor(renderer, 255,0,0, 0); // Lime color
    SDL_RenderDrawLine(renderer, 600, 196+30*x, 635, 196+30*x);
    SDL_RenderDrawLine(renderer, 600, 196+30*x, 610, 186+30*x);
    SDL_RenderDrawLine(renderer, 600, 196+30*x, 610, 206+30*x);
}

int menuArrow2(SDL_Renderer *renderer, int x){
    SDL_SetRenderDrawColor(renderer, 255,0,0, 0); // Lime color
    SDL_RenderDrawLine(renderer, 600, 206+30*x, 635, 206+30*x);
    SDL_RenderDrawLine(renderer, 600, 206+30*x, 610, 196+30*x);
    SDL_RenderDrawLine(renderer, 600, 206+30*x, 610, 216+30*x);
}

void menu(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 255, 140, 0, 255); // Orange color
    SDL_Rect menu1 = {525, 125, 50, 50};
    SDL_RenderFillRect(renderer, &menu1);

    SDL_SetRenderDrawColor(renderer, 173, 255, 47, 0); // Green color
    SDL_Rect menu2 = {525, 255, 50, 50};
    SDL_RenderFillRect(renderer, &menu2);

    vPeople(renderer);
    vAI(renderer);
    save(renderer);
    load(renderer);
    arrow(renderer);
}
