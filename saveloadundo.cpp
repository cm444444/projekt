#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "saveloadundo.h"

void undoRect3v3(SDL_Renderer *renderer, int xundo, int yundo){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black color
    SDL_Rect rectblack1 = {133+133*xundo, 133+133*yundo, 66, 66};
    SDL_RenderFillRect(renderer, &rectblack1);
}

void undoRect5v5(SDL_Renderer *renderer, int xundo, int yundo){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black color
    SDL_Rect rectblack2 = {104+20*xundo, 104+20*yundo, 13, 13};
    SDL_RenderFillRect(renderer, &rectblack2);
}

void saveGame(int tabv3[3][3], int tabv5[20][20], int undoTurn, int *loadFlag){

    FILE *file = fopen("save.txt","w");
    if(undoTurn == 0 || undoTurn == 1){
        char temp[10];
        for(int a = 0;a <= 2; a++){
            for(int b = 0;b <= 2; b++){
                itoa(tabv3[b][a],temp,10);
                fputs(temp , file );
            }
            printf("\n");
        }
        (*loadFlag) = 1;
    }
    else if(undoTurn == 2 || undoTurn == 3){
        char temp[401];
        for(int a = 0;a <= 19; a++){
            for(int b = 0;b <= 19; b++){
                itoa(tabv5[b][a],temp,10);
                fputs(temp , file );
            }
            printf("\n");
        }
        (*loadFlag) = 2;
    }
    fclose(file);
}

void loadGame3v3(SDL_Renderer *renderer, int tabv3[3][3]){


        FILE *file = fopen("save.txt","r");
        for(int a = 0;a <= 2; a++){
            for(int b = 0;b <= 2; b++){
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Tomato color
                SDL_Rect rectblack = {133+133*b, 133+133*a, 66, 66};
                SDL_RenderFillRect(renderer, &rectblack);
            }
        }
        char temp[10];
        for(int a = 0;a <= 2; a++){
            for(int b = 0;b <= 2; b++){
                tabv3[b][a] = atoi(temp);
                tabv3[b][a] = getc(file);
                tabv3[b][a] = tabv3[b][a] - 48;
                if(tabv3[b][a] == 1){
                    SDL_SetRenderDrawColor(renderer, 255, 99, 71, 255); // Tomato color
                    SDL_Rect rectred = {133+133*b, 133+133*a, 66, 66};
                    SDL_RenderFillRect(renderer, &rectred);
                }
                else if(tabv3[b][a] == 2){
                    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Blue color
                    SDL_Rect rectblue = {133+133*b, 133+133*a, 66, 66};
                    SDL_RenderFillRect(renderer, &rectblue);
                }
            }
            printf("\n");
        }fclose(file);

}

void loadGame5v5(SDL_Renderer *renderer, int tabv5[20][20]){


        FILE *file = fopen("save.txt","r");
        for(int a = 0;a <= 19; a++){
            for(int b = 0;b <= 19; b++){
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_Rect rectblack2 = {104+20*b, 104+20*a, 13, 13};
                SDL_RenderFillRect(renderer, &rectblack2);
            }
        }
        char temp[401];
        for(int a = 0;a <= 19; a++){
            for(int b = 0;b <= 19; b++){
                tabv5[b][a] = atoi(temp);
                tabv5[b][a] = getc(file);
                tabv5[b][a] = tabv5[b][a] - 48;
                if(tabv5[b][a] == 1){
                    SDL_SetRenderDrawColor(renderer, 255, 99, 71, 255); // Tomato color
                    SDL_Rect rectred2 = {104+20*b, 104+20*a, 13, 13};
                    SDL_RenderFillRect(renderer, &rectred2);
                }
                else if(tabv5[b][a] == 2){
                    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Blue color
                    SDL_Rect rectblue2 = {104+20*b, 104+20*a, 13, 13};
                    SDL_RenderFillRect(renderer, &rectblue2);
                }
            }
            printf("\n");
        }fclose(file);


}
