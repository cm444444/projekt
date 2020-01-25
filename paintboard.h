#ifndef PAINTBOARD_H
#define PAINTBOARD_H

void v3board(int nr_lines, bool color, SDL_Renderer *renderer);
void v5board(int nr_lines, bool color, SDL_Renderer *renderer);
void firstLayout(SDL_Renderer *renderer);
void tabv3Prepare(int tabv3[3][3]);
void tabv5Prepare(int tabv5[20][20]);
void smallLine(SDL_Renderer *renderer, int x, int y);
void smallBlackLine(SDL_Renderer *renderer, int x, int y);
void longLine(SDL_Renderer *renderer, int x, int y);
void longBlackLine(SDL_Renderer *renderer, int x, int y);

#endif
