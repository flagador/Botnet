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
int shop(SDL_Renderer * Render, SDL_Window * Window, jeu_t *jeu, upgrade_t *phishing, upgrade_t *cles_usb, upgrade_t *trojan, upgrade_t *fake_ad, upgrade_t *backdoor, upgrade_t *boot_sector, upgrade_t *spyware, upgrade_t *polymorphic, TTF_Font * font);
int nameVirus(SDL_Renderer * Render, SDL_Window * Window, char ** textaa, TTF_Font * font);
//void initRect(SDL_Renderer * render ,SDL_Rect * rect, int x, int y , int w, int h,int r,int g,int b, int alpha);
  void initRect(SDL_Renderer * render ,SDL_Rect * rect, int x, int y , int w, int h,int r,int g,int b, int alpha);

int isOnButton(SDL_Rect rect);

void showText(SDL_Renderer * render, SDL_Rect * rect, const char *text, TTF_Font * font, SDL_Color *color);

void showSmallerText(SDL_Renderer * render, SDL_Rect * rect, const char *text, TTF_Font * font, SDL_Color *color);
int SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius);
int SDL_RenderDrawCircle(SDL_Renderer * renderer, int x, int y, int radius);
void drawCountryPoint(SDL_Renderer * renderer,country_list_t * cl ,hitbox_t hitRussie,hitbox_t hitAmeriqueCentre, hitbox_t hitCoreeSud, hitbox_t hitCoreeNord, hitbox_t hitOceanie, hitbox_t hitBresil, hitbox_t hitAmeriqueNord, hitbox_t hitInde, hitbox_t hitChine , hitbox_t hitOuest, hitbox_t hitEst, hitbox_t hitAffriqueNord, hitbox_t hitMoyOrient, hitbox_t hitAffriqueSud, hitbox_t hitAffriqueCentre);
#endif
