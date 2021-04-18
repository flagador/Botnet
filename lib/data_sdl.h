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

typedef struct texture_list_s texture_list_t;
struct texture_list_s{ 
  int nb;
  SDL_Texture **textures;
};


int mainMenu();
void startNewGame();
void genererShop(SDL_Rect *Items, SDL_Renderer * Render, upgrade_list_t * up_list, TTF_Font *font);
int shop(SDL_Renderer * Render, SDL_Window * Window, jeu_t *jeu, upgrade_list_t * up_list, TTF_Font * font, Mix_Chunk *Select,Mix_Chunk *Error, texture_list_t * texturesButton);
int nameVirus(SDL_Renderer * Render, SDL_Window * Window, char ** textaa, TTF_Font * font);
//void initRect(SDL_Renderer * render ,SDL_Rect * rect, int x, int y , int w, int h,int r,int g,int b, int alpha);
void initRect(SDL_Renderer * render ,SDL_Rect * rect, int x, int y , int w, int h,int r,int g,int b, int alpha);
int isOnButton(SDL_Rect rect);
void showText(SDL_Renderer * render, SDL_Rect * rect, const char *text, TTF_Font * font, SDL_Color *color);
void showSmallerText(SDL_Renderer * render, SDL_Rect * rect, const char *text, TTF_Font * font, SDL_Color *color, int y);
int SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius);
int SDL_RenderDrawCircle(SDL_Renderer * renderer, int x, int y, int radius);
void drawCountryPoint(country_list_t *cl, texture_list_t * textures);
void destroyTexture(texture_list_t ** texture);
texture_list_t * creer_texture_list(SDL_Renderer * render, char fichierloc[25]);
int getInfo(SDL_Renderer * pRenderer, SDL_Window * pWindow, country_list_t * cl,TTF_Font * font, Mix_Chunk *Select,texture_list_t* texturesButton);
int saveExist();
#endif
