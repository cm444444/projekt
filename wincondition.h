#ifndef WINCONDITION_H
#define WINCONDITION_H

void v3Win(int tabv3[3][3], SDL_Renderer *renderer, int turn, int *endOfBattle);
void v5Win(int tabv5[20][20], SDL_Renderer *renderer, int turn, int *endOfBattle);
void drawV3(int tabv3[3][3], SDL_Renderer *renderer, int *endOfBattle);
void drawV5(int tabv5[20][20], SDL_Renderer *renderer, int *endOfBattle);
void winLook(SDL_Renderer *renderer, int turn);
void drawLook(SDL_Renderer *renderer);

#endif
