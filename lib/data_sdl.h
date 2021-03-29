#ifndef _DATA_SDL_H_
#define _DATA_SDL_H_

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>   
#include "../lib/jeu.h"
#include "../lib/upgrade.h"


#define LONG 1080
#define HAUT 720

typedef struct hitbox_s hitbox_t;
struct hitbox_s{ 
  int x;
  int y;
  int w;
  int h;
};


int mainMenu();
void startNewGame();
int shop(SDL_Renderer * Render, SDL_Window * Window, jeu_t *jeu, upgrade_t *upgrade, upgrade_t *cles_usb, upgrade_t *trojan, upgrade_t *fake_ad);
int nameVirus(SDL_Renderer * Render, SDL_Window * Window, char ** textaa);
//void initRect(SDL_Renderer * render ,SDL_Rect * rect, int x, int y , int w, int h,int r,int g,int b, int alpha);
  void initRect(SDL_Renderer * render ,SDL_Rect * rect, int x, int y , int w, int h,int r,int g,int b, int alpha);

int isOnButton(SDL_Rect rect);

void showText(SDL_Renderer * render, SDL_Rect * rect, const char *text, TTF_Font * font, SDL_Color *color);

#endif
