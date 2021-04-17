#ifndef _DATA_SDL_H_
#define _DATA_SDL_H_

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>   
#include "../lib/jeu.h"
#include "../lib/upgrade_list.h"


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
int shop(SDL_Renderer * Render, SDL_Window * Window, jeu_t *jeu, upgrade_list_t * up_list, TTF_Font * font, Mix_Chunk *Select,Mix_Chunk *Error);
int nameVirus(SDL_Renderer * Render, SDL_Window * Window, char ** textaa, TTF_Font * font);
//void initRect(SDL_Renderer * render ,SDL_Rect * rect, int x, int y , int w, int h,int r,int g,int b, int alpha);
  void initRect(SDL_Renderer * render ,SDL_Rect * rect, int x, int y , int w, int h,int r,int g,int b, int alpha);

int isOnButton(SDL_Rect rect);

void showText(SDL_Renderer * render, SDL_Rect * rect, const char *text, TTF_Font * font, SDL_Color *color);

void showSmallerText(SDL_Renderer * render, SDL_Rect * rect, const char *text, TTF_Font * font, SDL_Color *color, int y);
int SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius);
int SDL_RenderDrawCircle(SDL_Renderer * renderer, int x, int y, int radius);
void drawCountryPoint(country_list_t *cl, SDL_Texture * mapAffC,SDL_Texture * mapAffN,SDL_Texture * mapAffS,SDL_Texture * mapAmeriqueC,SDL_Texture * mapAmeriqueN,SDL_Texture * mapAmeriqueS,SDL_Texture * mapAsie,SDL_Texture * mapBresil,SDL_Texture * mapChine,SDL_Texture * mapCoreN,SDL_Texture * mapCoreS,SDL_Texture * mapEurEs,SDL_Texture * mapEurOu,SDL_Texture * mapInde,SDL_Texture * mapJapon,SDL_Texture * mapMoyO,SDL_Texture * mapOceanie,SDL_Texture * mapRussie);
#endif
