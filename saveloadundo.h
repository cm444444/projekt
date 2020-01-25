#ifndef SAVELOADUNDO_H
#define SAVELOADUNDO_H

void undoRect3v3(SDL_Renderer *renderer, int xundo, int yundo);
void undoRect5v5(SDL_Renderer *renderer, int xundo, int yundo);
void saveGame(int tabv3[3][3], int tabv5[20][20], int undoTurn, int *loadFlag);
void loadGame3v3(SDL_Renderer *renderer, int tabv3[3][3]);
void loadGame5v5(SDL_Renderer *renderer, int tabv5[20][20]);


#endif
