#ifndef _DATA_SDL_H_
#define _DATA_SDL_H_

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>   


#define LONG 1080
#define HAUT 720


int mainMenu();
void startNewGame();
int shop(SDL_Renderer * Render, SDL_Window * Window);
//void initRect(SDL_Renderer * render ,SDL_Rect * rect, int x, int y , int w, int h,int r,int g,int b, int alpha);
  void initRect(SDL_Renderer * render ,SDL_Rect * rect, int x, int y , int w, int h,int r,int g,int b, int alpha);

int isOnButton(SDL_Rect rect);
void DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
void showText(SDL_Renderer * render, SDL_Rect * rect, const char *text, TTF_Font * font, SDL_Color *color);

#endif
