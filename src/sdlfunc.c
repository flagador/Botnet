#include "../lib/data_sdl.h"
#include "../lib/country_list.h"
#include <unistd.h>
#include <stdio.h>

void showText(SDL_Renderer * render, SDL_Rect * rect, const char *text, TTF_Font * font, SDL_Color *color){
    SDL_Surface *surface;
    SDL_Texture *texture;

    surface = TTF_RenderText_Solid(font, text, *color);
    texture = SDL_CreateTextureFromSurface(render, surface);

    SDL_Rect message_rect;
    message_rect.x = rect->x;
    message_rect.y = rect->y;
    message_rect.w = rect->w;
    message_rect.h = rect->h;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render, texture, NULL , &message_rect);
    SDL_DestroyTexture(texture);
}
void showSmallerText(SDL_Renderer * render, SDL_Rect * rect, const char *text, TTF_Font * font, SDL_Color *color){
    SDL_Surface *surface;
    SDL_Texture *texture;

    surface = TTF_RenderText_Solid(font, text, *color);
    texture = SDL_CreateTextureFromSurface(render, surface);

    SDL_Rect message_rect;
    message_rect.x = rect->x;
    message_rect.y = rect->y;
    message_rect.w = rect->w/2;
    message_rect.h = rect->h/4;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render, texture, NULL , &message_rect);
    SDL_DestroyTexture(texture);
}

/*
void initText(SDL_Surface * surface, SDL_Texture * texture, TTF_Font * font, SDL_Renderer * render, SDL_Color color ,char * text){
    surface = TTF_RenderText_Blended(font , text, color);
    texture = SDL_CreateTextureFromSurface(render, surface);
}*/

void initRect(SDL_Renderer * render ,SDL_Rect * rect, int x, int y , int w, int h, int r,int g,int b, int alpha){
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;

    SDL_SetRenderDrawColor(render, r,g,b,alpha);
    SDL_RenderFillRect(render, rect);
}

int isOnButton(SDL_Rect rect){
    int x,y;
    SDL_GetMouseState(&x, &y);
    printf("x = %i , y = %i \n", x,y);
    if( (x > rect.x && x < (rect.x+rect.w)) && (y > rect.y && y < (rect.y+rect.h)))
        return 1;
    return 0;
}
/*
SDL_RenderDrawCircle(SDL_Renderer * render, SDL_Rect * rect, int r,int g,int b, int alpha);

SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius);
*/