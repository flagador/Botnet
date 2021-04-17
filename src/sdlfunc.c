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
    //printf("x = %i , y = %i \n", x,y);
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

void drawCountryPoint(country_list_t *cl,SDL_Texture * mapAffC,SDL_Texture * mapAffN,SDL_Texture * mapAffS,SDL_Texture * mapAmeriqueC,SDL_Texture * mapAmeriqueN,SDL_Texture * mapAmeriqueS,SDL_Texture * mapAsie,SDL_Texture * mapBresil,SDL_Texture * mapChine,SDL_Texture * mapCoreN,SDL_Texture * mapCoreS,SDL_Texture * mapEurEs,SDL_Texture * mapEurOu,SDL_Texture * mapInde,SDL_Texture * mapJapon,SDL_Texture * mapMoyO,SDL_Texture * mapOceanie,SDL_Texture * mapRussie){
    SDL_SetTextureAlphaMod(mapAffC, cl->liste[5]->compromised_pcs_cpt*255 / (cl->liste[5]->healthy_pcs_cpt + cl->liste[5]->compromised_pcs_cpt));        
    SDL_SetTextureAlphaMod(mapAffN, cl->liste[3]->compromised_pcs_cpt*255 / (cl->liste[3]->healthy_pcs_cpt + cl->liste[3]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapAffS, cl->liste[4]->compromised_pcs_cpt*255 / (cl->liste[4]->healthy_pcs_cpt + cl->liste[4]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapAmeriqueC, cl->liste[15]->compromised_pcs_cpt*255 / (cl->liste[15]->healthy_pcs_cpt + cl->liste[15]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapAmeriqueN, cl->liste[16]->compromised_pcs_cpt*255 / (cl->liste[16]->healthy_pcs_cpt + cl->liste[16]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapAmeriqueS, cl->liste[14]->compromised_pcs_cpt*255 / (cl->liste[14]->healthy_pcs_cpt + cl->liste[14]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapAsie, cl->liste[10]->compromised_pcs_cpt*255 / (cl->liste[10]->healthy_pcs_cpt + cl->liste[10]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapBresil, cl->liste[13]->compromised_pcs_cpt*255 / (cl->liste[13]->healthy_pcs_cpt + cl->liste[13]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapChine, cl->liste[8]->compromised_pcs_cpt*255 / (cl->liste[8]->healthy_pcs_cpt + cl->liste[8]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapCoreN, cl->liste[9]->compromised_pcs_cpt*255 / (cl->liste[9]->healthy_pcs_cpt + cl->liste[9]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapCoreS, cl->liste[17]->compromised_pcs_cpt*255 / (cl->liste[17]->healthy_pcs_cpt + cl->liste[17]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapEurEs, cl->liste[1]->compromised_pcs_cpt*255 / (cl->liste[1]->healthy_pcs_cpt + cl->liste[1]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapEurOu, cl->liste[0]->compromised_pcs_cpt*255 / (cl->liste[0]->healthy_pcs_cpt + cl->liste[0]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapInde, cl->liste[7]->compromised_pcs_cpt*255 / (cl->liste[7]->healthy_pcs_cpt + cl->liste[7]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapJapon, cl->liste[11]->compromised_pcs_cpt*255 / (cl->liste[11]->healthy_pcs_cpt + cl->liste[11]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapMoyO, cl->liste[6]->compromised_pcs_cpt*255 / (cl->liste[6]->healthy_pcs_cpt + cl->liste[6]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapOceanie, cl->liste[12]->compromised_pcs_cpt*255 / (cl->liste[12]->healthy_pcs_cpt + cl->liste[12]->compromised_pcs_cpt)); 
    SDL_SetTextureAlphaMod(mapRussie, cl->liste[2]->compromised_pcs_cpt*255 / (cl->liste[2]->healthy_pcs_cpt + cl->liste[2]->compromised_pcs_cpt)); 
}