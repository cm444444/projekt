#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "paintmenu.h"
#include "paintboard.h"
#include "saveloadundo.h"
#include "wincondition.h"
#include "paintrect.h"


static const int width = 700;
static const int height = 600;

 struct undo3V3 {
   int xundo;
   int yundo;
   int xundoAI;
   int yundoAI;
 }gamev3;

 struct undo5V5 {
   int xundo;
   int yundo;
   int xundoAI;
   int yundoAI;
 }gamev5;


int tabv3AI(int tabv3[3][3], SDL_Renderer *renderer,  struct undo3V3* gamev3){

    int tempA;int tempB;

    int a, b, spr;
    for( a = 0;a <= 2 ; a++){
        for( b = 0;b <= 2 ; b++){
                if(tabv3[a][b] == 1){
                    for(spr = 0; spr < 7; spr++){
                        tempA = a;tempB = b;

                        if(spr == 0){
                            ///sprawdzanie w pld
                            tempB++;
                            for( ;tempB <= 2;){
                                if(tabv3[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Blue color
                                    SDL_Rect rectgreen = {133+133*tempA, 133+133*tempB, 66, 66};
                                    SDL_RenderFillRect(renderer, &rectgreen);
                                    tabv3[tempA][tempB] = 2;
                                    gamev3->xundoAI = tempA;
                                    gamev3->yundoAI = tempB;
                                    return 0;
                                }
                                tempB++;
                            }
                        }
                        else if(spr == 1){
                        ///sprawdzanie w pld-wsch
                            tempA++;
                            tempB++;
                            for( ;tempA <= 2 && tempB <= 2;){
                                if(tabv3[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Blue color
                                    SDL_Rect rectgreen = {133+133*tempA, 133+133*tempB, 66, 66};
                                    SDL_RenderFillRect(renderer, &rectgreen);
                                    tabv3[tempA][tempB] = 2;
                                    gamev3->xundoAI = tempA;
                                    gamev3->yundoAI = tempB;
                                    return 0;
                                }
                                tempA++;
                                tempB++;
                            }
                        }
                        else if(spr == 2){
                                tempA++;
                        ///sprawdzanie w wsch
                            for( ;tempA <= 2;){
                                if(tabv3[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Blue color
                                    SDL_Rect rectgreen = {133+133*tempA, 133+133*tempB, 66, 66};
                                    SDL_RenderFillRect(renderer, &rectgreen);
                                    tabv3[tempA][tempB] = 2;
                                    gamev3->xundoAI = tempA;
                                    gamev3->yundoAI = tempB;
                                    return 0;
                                }
                                tempA++;
                            }
                        }
                        else if(spr == 3){
                        ///sprawdzanie w pn-wsch
                                tempA++;
                                tempB--;
                            for( ;tempA <= 2 && tempB >= 0;){
                                if(tabv3[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Blue color
                                    SDL_Rect rectgreen = {133+133*tempA, 133+133*tempB, 66, 66};
                                    SDL_RenderFillRect(renderer, &rectgreen);
                                    tabv3[tempA][tempB] = 2;
                                    gamev3->xundoAI = tempA;
                                    gamev3->yundoAI = tempB;
                                    for(int a = 0;a <= 2; a++){
                                       for(int b = 0;b <= 2; b++){
                                           printf("%d ",tabv3[b][a]);
                                       }printf("\n");
                                    }
                                    return 0;
                                }
                                tempA++;
                                tempB--;
                            }
                        }
                        else if(spr == 4){
                            tempB--;
                        ///sprawdzanie w pn
                            for( ;tempB >= 0;){
                                if(tabv3[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Blue color
                                    SDL_Rect rectgreen = {133+133*tempA, 133+133*tempB, 66, 66};
                                    SDL_RenderFillRect(renderer, &rectgreen);
                                    tabv3[tempA][tempB] = 2;
                                    gamev3->xundoAI = tempA;
                                    gamev3->yundoAI = tempB;
                                    return 0;
                                }
                                tempB--;
                            }
                        }
                        else if(spr == 5){
                            tempA--;
                            tempB--;
                        ///sprawdzanie w pn-zach
                            for( ;tempA >= 0 && tempB >= 0;){
                                if(tabv3[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Blue color
                                    SDL_Rect rectgreen = {133+133*tempA, 133+133*tempB, 66, 66};
                                    SDL_RenderFillRect(renderer, &rectgreen);
                                    tabv3[tempA][tempB] = 2;
                                    gamev3->xundoAI = tempA;
                                    gamev3->yundoAI = tempB;
                                    return 0;
                                }
                                tempA--;
                                tempB--;
                            }
                        }
                        else if(spr == 6){
                            tempA--;
                        ///sprawdzanie w zach
                            for( ;tempA >= 0;){
                                if(tabv3[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Blue color
                                    SDL_Rect rectgreen = {133+133*tempA, 133+133*tempB, 66, 66};
                                    SDL_RenderFillRect(renderer, &rectgreen);
                                    tabv3[tempA][tempB] = 2;
                                    gamev3->xundoAI = tempA;
                                    gamev3->yundoAI = tempB;
                                    return 0;
                                }
                                tempA--;
                            }
                        }
                        else if(spr == 7){
                            tempA--;
                            tempB++;
                        ///sprawdzanie w pd-zach
                            for( ;tempA >= 0 && tempB <= 2;){
                                if(tabv3[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255); // Blue color
                                    SDL_Rect rectgreen = {133+133*tempA, 133+133*tempB, 66, 66};
                                    SDL_RenderFillRect(renderer, &rectgreen);
                                    tabv3[tempA][tempB] = 2;
                                    gamev3->xundoAI = tempA;
                                    gamev3->yundoAI = tempB;
                                    return 0;
                                }
                                tempA--;
                                tempB++;
                            }
                        }
                    }
                }

        }

    }

}

int tabv5AI(int tabv5[20][20], SDL_Renderer *renderer,  struct undo5V5* gamev5){

    int tempA;int tempB;

    int a, b, spr;
    for( a = 0;a <= 19 ; a++){
        for( b = 0;b <= 19 ; b++){
                if(tabv5[a][b] == 1){
                    for(spr = 0; spr < 7; spr++){
                        tempA = a;tempB = b;

                        if(spr == 0){
                            ///sprawdzanie w pld
                            tempB++;
                            for( ;tempB <= 19;){
                                if(tabv5[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135,206,250, 255);
                                    SDL_Rect rectpink = {104+20*tempA, 104+20*tempB, 13, 13};
                                    SDL_RenderFillRect(renderer, &rectpink);
                                    tabv5[tempA][tempB] = 2;
                                    gamev5->xundoAI = tempA;
                                    gamev5->yundoAI = tempB;
                                    return 0;
                                }
                                tempB++;
                            }
                        }
                        else if(spr == 1){
                                tempA++;
                                tempB++;
                        ///sprawdzanie w pld-wsch
                            for( ;tempA <= 19 && tempB <= 19;){
                                if(tabv5[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135,206,250, 255);
                                    SDL_Rect rectpink = {104+20*tempA, 104+20*tempB, 13, 13};
                                    SDL_RenderFillRect(renderer, &rectpink);
                                    tabv5[tempA][tempB] = 2;
                                    gamev5->xundoAI = tempA;
                                    gamev5->yundoAI = tempB;
                                    return 0;
                                }
                                tempA++;
                                tempB++;
                            }
                        }
                        else if(spr == 2){
                            tempA++;
                        ///sprawdzanie w wsch
                            for( ;tempA <= 19;){
                                if(tabv5[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135,206,250, 255);
                                    SDL_Rect rectpink = {104+20*tempA, 104+20*tempB, 13, 13};
                                    SDL_RenderFillRect(renderer, &rectpink);
                                    tabv5[tempA][tempB] = 2;
                                    gamev5->xundoAI = tempA;
                                    gamev5->yundoAI = tempB;
                                    return 0;
                                }
                                tempA++;
                            }
                        }
                        else if(spr == 3){
                            tempA++;
                            tempB--;
                        ///sprawdzanie w pn-wsch
                            for( ;tempA <= 19 && tempB >= 0;){
                                if(tabv5[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135,206,250, 255);
                                    SDL_Rect rectpink = {104+20*tempA, 104+20*tempB, 13, 13};
                                    SDL_RenderFillRect(renderer, &rectpink);
                                    tabv5[tempA][tempB] = 2;
                                    gamev5->xundoAI = tempA;
                                    gamev5->yundoAI = tempB;
                                    return 0;
                                }
                                tempA++;
                                tempB--;
                            }
                        }
                        else if(spr == 4){
                        ///sprawdzanie w pn
                        tempB--;
                            for( ;tempB >= 0;){
                                if(tabv5[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135,206,250, 255);
                                    SDL_Rect rectpink = {104+20*tempA, 104+20*tempB, 13, 13};
                                    SDL_RenderFillRect(renderer, &rectpink);
                                    tabv5[tempA][tempB] = 2;
                                    gamev5->xundoAI = tempA;
                                    gamev5->yundoAI = tempB;
                                    return 0;
                                }
                                tempB--;
                            }
                        }
                        else if(spr == 5){
                        ///sprawdzanie w pn-zach
                        tempA--;
                        tempB--;
                            for( ;tempA >= 0 && tempB >= 0;){
                                if(tabv5[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135,206,250, 255);
                                    SDL_Rect rectpink = {104+20*tempA, 104+20*tempB, 13, 13};
                                    SDL_RenderFillRect(renderer, &rectpink);
                                    tabv5[tempA][tempB] = 2;
                                    gamev5->xundoAI = tempA;
                                    gamev5->yundoAI = tempB;
                                    return 0;
                                }
                                tempA--;
                                tempB--;
                            }
                        }
                        else if(spr == 6){
                            tempA--;
                        ///sprawdzanie w zach
                            for( ;tempA >= 0;){
                                if(tabv5[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135,206,250, 255);
                                    SDL_Rect rectpink = {104+20*tempA, 104+20*tempB, 13, 13};
                                    SDL_RenderFillRect(renderer, &rectpink);
                                    tabv5[tempA][tempB] = 2;
                                    gamev5->xundoAI = tempA;
                                    gamev5->yundoAI = tempB;
                                    return 0;
                                }
                                tempA--;
                            }
                        }
                        else if(spr == 7){
                            tempA--;
                            tempB++;
                        ///sprawdzanie w pd-zach
                            for( ;tempA >= 0 && tempB <= 19;){
                                if(tabv5[tempA][tempB] == 0){
                                    SDL_SetRenderDrawColor(renderer, 135,206,250, 255);
                                    SDL_Rect rectpink = {104+20*tempA, 104+20*tempB, 13, 13};
                                    SDL_RenderFillRect(renderer, &rectpink);
                                    tabv5[tempA][tempB] = 2;
                                    gamev5->xundoAI = tempA;
                                    gamev5->yundoAI = tempB;
                                    return 0;
                                }
                                tempA--;
                                tempB++;
                            }
                        }
                    }
                }
        }

    }

}


int main(int argc, char **argv)
{
    int x = 0;
    int y = 0;
    int warBattle = 0; /// ktore pole bitwy, jest aktualnie uzywane
    int turn = 0; /// czyja tura
    int tabv5[20][20];
    int tabv3[3][3];
    int endOfBattle = 0;
    int turnAI = 0; /// walka z AI
    int undoTurn = 0;
    int loadFlag = 0;
    struct undo3V3 gamev3;
    struct undo5V5 gamev5;
    gamev3.xundo = 0;
    gamev3.yundo = 0;
    gamev3.xundoAI = 0;
    gamev3.yundoAI = 0;
    gamev5.xundo = 0;
    gamev5.yundo = 0;
    gamev5.xundoAI = 0;
    gamev5.yundoAI = 0;

    tabv3Prepare(tabv3);
    tabv5Prepare(tabv5);

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    /// Creating a SDL window
    SDL_Window *window = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

    /// Creating a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    firstLayout(renderer);
    menu(renderer);
    menuArrow1(renderer, 0);


    bool running = true;
    SDL_Event event;
    while(running)
    {
        // Process events
        while(SDL_PollEvent(&event))
        {
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:

                    switch(event.key.keysym.sym){
                        case SDLK_LEFT:
                            if(warBattle == 0){
                                if(x > 0){
                                    longBlackLine(renderer, x, y);
                                    x = x - 1;
                                    longLine(renderer, x, y);
                                    break;
                                }
                                else
                                    break;
                            }
                            else{
                                if(x > 0){
                                    smallBlackLine(renderer, x, y);
                                    x = x - 1;
                                    smallLine(renderer, x, y);
                                    break;
                                }
                                else
                                    break;
                            }


                        case SDLK_RIGHT:
                            if(warBattle == 0){
                                if(x < 2){
                                    longBlackLine(renderer, x, y);
                                    x = x + 1;
                                    longLine(renderer, x, y);
                                    break;
                                }
                                else
                                    break;
                            }
                            else{
                                if(x < 19){
                                    smallBlackLine(renderer, x, y);
                                    x = x + 1;
                                    smallLine(renderer, x, y);
                                    break;
                                }
                                else
                                    break;
                            }

                        case SDLK_UP:
                            if(warBattle == 0){
                                if(y > 0){
                                    longBlackLine(renderer, x, y);
                                    y = y - 1;
                                    longLine(renderer, x, y);
                                    break;
                                }
                                else
                                    break;
                            }
                            else{
                                if(y > 0){
                                    smallBlackLine(renderer, x, y);
                                    y = y - 1;
                                    smallLine(renderer, x, y);
                                    break;
                                }
                                else
                                    break;
                            }

                        case SDLK_DOWN:
                            if(warBattle == 0){
                                if(y < 2){
                                    longBlackLine(renderer, x, y);
                                    y = y + 1;
                                    longLine(renderer, x, y);
                                    break;
                                }
                                else
                                    break;
                            }
                            else{
                                if(y < 19){
                                    smallBlackLine(renderer, x, y);
                                    y = y + 1;
                                    smallLine(renderer, x, y);
                                     break;
                                }
                                else
                                    break;
                            }
                        case SDLK_SPACE:
                            if(endOfBattle == 0){
                                if(warBattle == 0){
                                    if(y >= 0 && y <= 2 && x >= 0 && x <= 2){

                                        if(turn == 0){
                                            if(turnAI == 0){
                                                if(tabv3[x][y] == 0){
                                                    tomatoBigRect(renderer, x, y);
                                                    tabv3[x][y] = 1;
                                                    v3Win(tabv3, renderer, turn, &endOfBattle);
                                                    drawV3(tabv3, renderer, &endOfBattle); /// remis
                                                    turn = 1;
                                                    gamev3.xundo = x;
                                                    gamev3.yundo = y;
                                                }
                                                else
                                                    break;
                                            }
                                            else{
                                                if(tabv3[x][y] == 0){
                                                    tomatoBigRect(renderer, x, y);
                                                    tabv3[x][y] = 1;
                                                    v3Win(tabv3, renderer, turn, &endOfBattle);
                                                    drawV3(tabv3, renderer, &endOfBattle); /// remis
                                                    turn = 1;
                                                    gamev3.xundo = x;
                                                    gamev3.yundo = y;

                                                    if(endOfBattle == 0){
                                                        tabv3AI(tabv3, renderer, &gamev3);
                                                        v3Win(tabv3, renderer, turn, &endOfBattle);
                                                        drawV3(tabv3, renderer, &endOfBattle); /// remis
                                                        turn = 0;
                                                    }
                                                    else
                                                        break;
                                                }
                                                else
                                                    break;
                                            }
                                        }

                                        else{

                                            if(tabv3[x][y] == 0){
                                                blueBigRect(renderer, x, y);
                                                tabv3[x][y] = 2;
                                                v3Win(tabv3, renderer, turn, &endOfBattle);
                                                drawV3(tabv3, renderer, &endOfBattle); /// remis
                                                turn = 0;
                                                gamev3.xundo = x;
                                                gamev3.yundo = y;
                                            }
                                            else
                                                break;
                                        }
                                    }
                                    else
                                        break;
                                }
                                else{
                                    if(y >= 0 && y <= 19 && x >= 0 && x <= 19){
                                        if(turn == 0){
                                            if(turnAI == 0){
                                                if(tabv5[x][y] == 0){
                                                tomatoSmallRect(renderer, x, y);
                                                tabv5[x][y] = 1;
                                                v5Win(tabv5, renderer, turn, &endOfBattle);
                                                drawV5(tabv5, renderer, &endOfBattle); /// remis
                                                turn = 1;
                                                gamev5.xundo = x;
                                                gamev5.yundo = y;
                                                }
                                                else
                                                    break;
                                            }
                                            else{
                                                if(tabv5[x][y] == 0){
                                                    tomatoSmallRect(renderer, x, y);
                                                    tabv5[x][y] = 1;
                                                    v5Win(tabv5, renderer, turn, &endOfBattle);
                                                    drawV5(tabv5, renderer, &endOfBattle); /// remis
                                                    turn = 1;
                                                    gamev5.xundo = x;
                                                    gamev5.yundo = y;
                                                    if(endOfBattle == 0){
                                                        tabv5AI(tabv5, renderer, &gamev5);
                                                        v5Win(tabv5, renderer, turn, &endOfBattle);
                                                        drawV5(tabv5, renderer, &endOfBattle); /// remis
                                                        turn = 0;
                                                    }
                                                    else
                                                        break;
                                                }
                                                else
                                                    break;
                                            }
                                        }
                                        else{

                                            if(tabv5[x][y] == 0){
                                                blueSmallRect(renderer, x, y);
                                                tabv5[x][y] = 2;
                                                v5Win(tabv5, renderer, turn, &endOfBattle);
                                                drawV5(tabv5, renderer, &endOfBattle); /// remis
                                                turn = 0;
                                                gamev5.xundo = x;
                                                gamev5.yundo = y;
                                            }
                                            else
                                                break;
                                        }
                                    }
                                    else{
                                        break;
                                    }
                                }
                        }
                         else
                            break;

                    }
                    break;
                        case SDL_MOUSEBUTTONDOWN:
                            if( 535 <  event.motion.x && event.motion.x < 565 && 185 < event.motion.y && event.motion.y < 205){
                                    /// 3v3 ------- 1v1
                                tabv3Prepare(tabv3);
                                blackrect(renderer);
                                v3board(4, true, renderer);
                                menuArrow1(renderer, 0);
                                warBattle = 0;
                                x = 0;
                                y = 0;
                                turn = 0;
                                undoTurn = 0;
                                endOfBattle = 0;
                                turnAI = 0;
                                longLine(renderer, x, y);
                                }
                            else if( 535 <  event.motion.x && event.motion.x < 585 && 215 < event.motion.y && event.motion.y < 235){
                                    /// 3v3 --------- vs AI
                                tabv3Prepare(tabv3);
                                blackrect(renderer);
                                v3board(4, true, renderer);
                                menuArrow1(renderer, 1);
                                warBattle = 0;
                                x = 0;
                                y = 0;
                                turn = 0;
                                undoTurn = 1;
                                endOfBattle = 0;
                                turnAI = 1;
                                longLine(renderer, x, y);
                                }
                            else if( 535 <  event.motion.x && event.motion.x < 565 && 315 < event.motion.y && event.motion.y < 335){
                                    /// 5v5 --------- 1v1
                                tabv5Prepare(tabv5);
                                blackrect(renderer);
                                v5board(21, true, renderer);
                                menuArrow2(renderer, 4);
                                warBattle = 1;
                                x = 0;
                                y = 0;
                                turn = 0;
                                undoTurn = 2;
                                endOfBattle = 0;
                                turnAI = 0;
                                smallLine(renderer, x, y);
                            }
                            else if( 535 <  event.motion.x && event.motion.x < 585 && 345 < event.motion.y && event.motion.y < 365){
                                    /// 5v5 ---------- vs AI
                                tabv5Prepare(tabv5);
                                blackrect(renderer);
                                v5board(21, true, renderer);
                                menuArrow2(renderer, 5);
                                warBattle = 1;
                                x = 0;
                                y = 0;
                                turn = 0;
                                undoTurn = 3;
                                endOfBattle = 0;
                                turnAI = 1;
                                smallLine(renderer, x, y);
                            }
                            else if( 620 <  event.motion.x && event.motion.x < 670 && 370 < event.motion.y && event.motion.y < 420){
                                /// SAVE
                                int add = 0;
                                    if(undoTurn == 0 || undoTurn == 1){
                                        for(int a = 0;a <= 2; a++){
                                            for(int b = 0;b <= 2; b++){
                                                if(tabv3[b][a] != 0){
                                                    add++;
                                                }
                                            }
                                        }
                                        if(add % 2 == 0){
                                            saveGame(tabv3, tabv5, undoTurn, &loadFlag);
                                        }
                                    }
                                    else if(undoTurn == 2 || undoTurn == 3){
                                        for(int a = 0;a <= 19; a++){
                                            for(int b = 0;b <= 19; b++){
                                                if(tabv5[b][a] != 0){
                                                    add++;
                                                }
                                            }
                                        }
                                        if(add % 2 == 0){
                                            saveGame(tabv3, tabv5, undoTurn, &loadFlag);
                                        }
                                    }
                                    add=0;
                            }
                            else if( 620 <  event.motion.x && event.motion.x < 670 && 450 < event.motion.y && event.motion.y < 500){
                                ///LOAD
                                if(loadFlag == 1 && undoTurn == 0 || loadFlag == 1 && undoTurn == 1){
                                    loadGame3v3(renderer, tabv3);
                                }
                                else if(loadFlag == 2 && undoTurn == 2 || loadFlag == 2 && undoTurn == 3){
                                    loadGame5v5(renderer, tabv5);
                                }
                            }
                            else if( 600 <  event.motion.x && event.motion.x < 670 && 500 < event.motion.y && event.motion.y < 570){

                                if(undoTurn == 0){
                                    if(turn == 1){
                                       undoRect3v3(renderer, gamev3.xundo, gamev3.yundo);
                                       tabv3[gamev3.xundo][gamev3.yundo] = 0;
                                       turn = 0;
                                       }
                                    else{
                                        undoRect3v3(renderer, gamev3.xundo, gamev3.yundo);
                                        tabv3[gamev3.xundo][gamev3.yundo] = 0;
                                        turn = 1;
                                    }
                                    break;
                                }
                                else if(undoTurn == 1){
                                    if(turn == 0){
                                       undoRect3v3(renderer, gamev3.xundo, gamev3.yundo);
                                       undoRect3v3(renderer, gamev3.xundoAI, gamev3.yundoAI);
                                       tabv3[gamev3.xundo][gamev3.yundo] = 0;
                                       tabv3[gamev3.xundoAI][gamev3.yundoAI] = 0;;
                                    }
                                }
                                else if(undoTurn == 2){
                                    if(turn == 1){
                                       undoRect5v5(renderer, gamev5.xundo, gamev5.yundo);
                                       tabv5[gamev5.xundo][gamev5.yundo] = 0;
                                       turn = 0;
                                    }
                                    else{
                                        undoRect5v5(renderer, gamev5.xundo, gamev5.yundo);
                                        tabv5[gamev5.xundo][gamev5.yundo] = 0;
                                        turn = 1;
                                    }
                                    break;
                                }
                                else if(undoTurn == 3){
                                    if(turn == 0){
                                       undoRect5v5(renderer, gamev5.xundo, gamev5.yundo);
                                       undoRect5v5(renderer, gamev5.xundoAI, gamev5.yundoAI);
                                       tabv5[gamev5.xundo][gamev5.yundo] = 0;
                                       tabv5[gamev5.xundoAI][gamev5.yundoAI] = 0;
                                    }
                                }
                            }
                            break;
                        default:
                            break;
                    }
            }

        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Yellow color

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
