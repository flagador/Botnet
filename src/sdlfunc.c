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
void showSmallerText(SDL_Renderer * render, SDL_Rect * rect, const char *text, TTF_Font * font, SDL_Color *color, int y){
    SDL_Surface *surface;
    SDL_Texture *texture;

    surface = TTF_RenderText_Solid(font, text, *color);
    texture = SDL_CreateTextureFromSurface(render, surface);

    SDL_Rect message_rect;
    message_rect.x = rect->x;
    message_rect.y = y;
    message_rect.w = rect->w;
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

int SDL_RenderDrawCircle(SDL_Renderer * renderer, int x, int y, int radius){
    int offsetx, offsety, d;
    int status;


    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;

    while (offsety >= offsetx) {
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y - offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}

int SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius){
    int offsetx, offsety, d;
    int status;


    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;

    while (offsety >= offsetx) {

        status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx,x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety,x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety,x + offsetx, y - offsety);
        status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx,x + offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}

void drawCountryPoint(SDL_Renderer * renderer, country_list_t * cl ,hitbox_t hitRussie,hitbox_t hitAmeriqueCentre, hitbox_t hitCoreeSud, hitbox_t hitCoreeNord, hitbox_t hitOceanie, hitbox_t hitBresil, hitbox_t hitAmeriqueNord, hitbox_t hitInde, hitbox_t hitChine , hitbox_t hitOuest, hitbox_t hitEst, hitbox_t hitAffriqueNord, hitbox_t hitMoyOrient, hitbox_t hitAffriqueSud, hitbox_t hitAffriqueCentre){
    int buff;
    int i, rX, rY;
    //Russie
    buff = 30;//cl->liste[2]->compromised_pcs_cpt*100 / (cl->liste[2]->healthy_pcs_cpt + cl->liste[2]->compromised_pcs_cpt);
    for(i = 0 ; i<buff ; i++){
        //rX = rand()%((hitRussie.x+hitRussie.w) - hitRussie.x ) + (hitRussie.x+hitRussie.w);
        //rY = rand()%((hitRussie.y+hitRussie.h) - hitRussie.y ) + (hitRussie.y+hitRussie.h);
        //printf("rX -> %d, rY -> %d \n", rX, rY);
        SDL_RenderFillCircle(renderer, hitRussie.x + hitRussie.w, hitRussie.y, 5);
        SDL_RenderDrawCircle(renderer, hitRussie.x + hitRussie.w, hitRussie.y, 5);
    }
}