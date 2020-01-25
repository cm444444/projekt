#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "wincondition.h"

void v3Win(int tabv3[3][3], SDL_Renderer *renderer, int turn, int *endOfBattle){
    int a, b, i = 0, j = 0;
    for( a = 0;a <= 2; a++){
        for( b = 0;b <= 2; b++){
            if(turn == 0){
                if(tabv3[a][b] == 1){
                    i = i + 1;
                }
            }
            else{
                if(tabv3[a][b] == 2){
                    j = j + 1;
                }
            }
        }
        if(i == 3){
            winLook(renderer, turn);
            (*endOfBattle) = 1;
        }
        if(j == 3){
            winLook(renderer, turn);
            (*endOfBattle) = 1;
        }
        i = 0;
        j = 0;
    }

    for(a = 0;a <= 2; a++){
        for(b = 0;b <= 2; b++){
            if(turn == 0){
                if(tabv3[b][a] == 1){
                    i = i + 1;
                }
            }
            else{
                if(tabv3[b][a] == 2){
                    j = j + 1;
                }
            }
        }
        if(i == 3){
            winLook(renderer, turn);
            (*endOfBattle) = 1;
        }
        if(j == 3){
            winLook(renderer, turn);
           (*endOfBattle) = 1;
        }
        i = 0;
        j = 0;
    }

    for(a = 0, b = 0; a <= 2, b <= 2; a++, b++){
        if(turn == 0){
                if(tabv3[a][b] == 1){
                    i = i + 1;
                }
            }
        else{
            if(tabv3[a][b] == 2){
                j = j + 1;
            }
        }
    }
    if(i == 3){
        winLook(renderer, turn);
        (*endOfBattle) = 1;
    }
    if(j == 3){
        winLook(renderer, turn);
        (*endOfBattle) = 1;
    }
    i = 0;
    j = 0;

    for(a = 0, b = 2; a <= 2, b >= 0; a++, b--){
        if(turn == 0){
                if(tabv3[a][b] == 1){
                    i = i + 1;
                }
            }
        else{
            if(tabv3[a][b] == 2){
                j = j + 1;
            }
        }
    }
    if(i == 3){
        winLook(renderer, turn);
        (*endOfBattle) = 1;
    }
    if(j == 3){
        winLook(renderer, turn);
        (*endOfBattle) = 1;
    }
    i = 0;
    j = 0;

}

void v5Win(int tabv5[20][20], SDL_Renderer *renderer, int turn, int *endOfBattle){
    int a, b, i = 0, j = 0, spr;
    for( a = 0;a <= 19 && i<5 && j<5; a++){
        for( b = 0;b <= 19 && i<5 && j<5; b++){
            if(turn == 0){
                if(tabv5[a][b] == 1){
                    for(spr = 0; spr < 4; spr++){
                        int tempA = a;int tempB = b;
                        if(spr == 0){
                            ///sprawdzanie w pld
                            for( ;tempB <= 19;){
                                if(tabv5[tempA][tempB] == 1){
                                    i++;
                                }
                                else {
                                    i=0;
                                    break;
                                }
                                if(i == 5){
                                    winLook(renderer, turn);
                                    (*endOfBattle) = 1;
                                }
                                tempB++;
                            }
                        }
                        else if(spr == 1){
                        ///sprawdzanie w pld-wsch
                            for( ;tempA <= 19 && tempB <= 19;){
                                if(tabv5[tempA][tempB] == 1){
                                    i++;
                                }
                                else {
                                    i=0;
                                    break;
                                }
                                if(i==5){
                                    winLook(renderer, turn);
                                    (*endOfBattle) = 1;
                                }
                                tempA++;
                                tempB++;
                            }
                        }
                        else if(spr == 2){
                        ///sprawdzanie w wsch
                            for( ;tempA <= 19;){
                                if(tabv5[tempA][tempB] == 1){
                                    i++;
                                }
                                else {
                                    i=0;
                                    break;
                                }
                                if(i == 5){
                                    winLook(renderer, turn);
                                    (*endOfBattle) = 1;
                                }
                                tempA++;
                            }
                        }
                        else if(spr == 3){
                        ///sprawdzanie w pn-wsch
                            for( ;tempA <= 19 && tempB >= 0;){
                                if(tabv5[tempA][tempB] == 1){
                                    i++;
                                }
                                else {
                                    i=0;
                                    break;
                                }
                                if(i == 5){
                                    winLook(renderer, turn);
                                    (*endOfBattle) = 1;
                                }
                                tempA++;
                                tempB--;
                            }
                        }
                    }
                }
            }
            else{
                if(tabv5[a][b] == 2){
                    for(spr = 0; spr < 4; spr++){
                        int tempA = a;int tempB = b;
                        if(spr == 0){
                            ///sprawdzanie w pld
                            for( ;tempB <= 19;){
                                if(tabv5[tempA][tempB] == 2){
                                    j++;
                                }
                                else {
                                    j=0;
                                    break;
                                }
                                if(j == 5){
                                    winLook(renderer, turn);
                                    (*endOfBattle) = 1;
                                }
                                tempB++;
                            }
                        }
                        else if(spr == 1){
                        ///sprawdzanie w pld-wsch
                            for( ;tempA <= 19 && tempB <= 19;){
                                if(tabv5[tempA][tempB] == 2){
                                    j++;
                                }
                                else {
                                    j=0;
                                    break;
                                }
                                if(j == 5){
                                    winLook(renderer, turn);
                                    (*endOfBattle) = 1;
                                }
                                tempA++;
                                tempB++;
                            }
                        }
                        else if(spr == 2){
                        ///sprawdzanie w wsch
                            for( ;tempA <= 19;){
                                if(tabv5[tempA][tempB] == 2){
                                    j++;
                                }
                                else {
                                    j=0;
                                    break;
                                }
                                if(j == 5){
                                    winLook(renderer, turn);
                                    (*endOfBattle) = 1;
                                }
                                tempA++;
                            }
                        }
                        else if(spr == 3){
                        ///sprawdzanie w pn-wsch
                            for( ;tempA <= 19 && tempB >= 0;){
                                if(tabv5[tempA][tempB] == 2){
                                    j++;
                                }
                                else {
                                    j=0;
                                    break;
                                }
                                if(j == 5){
                                    winLook(renderer, turn);
                                    (*endOfBattle) = 1;
                                }
                                tempA++;
                                tempB--;
                            }
                        }
                    }
                }
            }
        }
    }
}

void drawV3(int tabv3[3][3], SDL_Renderer *renderer, int *endOfBattle){
    int i = 0;
    for(int a = 0;a <= 2; a++){
        for(int b = 0;b <= 2; b++){
            if(tabv3[a][b] == 0){
                i++;
            }
        }
    }
    if(i == 0){
        drawLook(renderer);
        (*endOfBattle) = 1;
    }
}

void drawV5(int tabv5[20][20], SDL_Renderer *renderer, int *endOfBattle){
    int i = 0;
    for(int a = 0;a <= 19; a++){
        for(int b = 0;b <= 19; b++){
            if(tabv5[a][b] == 0){
                i++;
            }
        }
    }
    if(i == 0){
        drawLook(renderer);
        (*endOfBattle) = 1;
    }

}

void winLook(SDL_Renderer *renderer, int turn){
    if(turn == 0){
        SDL_SetRenderDrawColor(renderer, 255, 99, 71, 255); // WINN
        SDL_Rect win = {525, 375, 50, 50};
        SDL_RenderFillRect(renderer, &win);
    }
    else{
        SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // WINN
        SDL_Rect win = {525, 375, 50, 50};
        SDL_RenderFillRect(renderer, &win);
    }
}

void drawLook(SDL_Renderer *renderer){

    SDL_SetRenderDrawColor(renderer, 255, 99, 71, 255);
    SDL_Rect draw1 = {525, 375, 25, 50};
    SDL_RenderFillRect(renderer, &draw1);
    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255);
    SDL_Rect draw2 = {550, 375, 25, 50};
    SDL_RenderFillRect(renderer, &draw2);

}
