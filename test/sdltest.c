#include "../lib/data_sdl.h"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = mainMenu();
    printf("a %i\n",a);
    switch(a){
        case 0:
            printf("QUIT ! \n");
            break;
        case 1:
            startNewGame();
            break;
        case 2:
            a=a;
            break;
    }
    return EXIT_SUCCESS;

}

int mainMenu(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Window* pWindow = NULL;    
    SDL_Renderer* pRenderer = NULL;
    SDL_Rect pstart, pcharge, pquit;
    SDL_Event events;

    SDL_Color white = {255,255,255};

    if (SDL_CreateWindowAndRenderer(LONG, HAUT, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());        
        SDL_Quit();         
        return EXIT_FAILURE;
    }

    
    int isOpen = 1 ;
    int ret = 0;
    TTF_Init();
    TTF_Font * font = TTF_OpenFont("../asset/Lato-Black.ttf", 60);
    if(font == NULL){
        printf("Aie \n");
    }
    /*SDL_Surface * sQuit = NULL;
    SDL_Texture * tQuit = NULL;
    SDL_Surface * sStart = NULL;
    SDL_Texture * tStart = NULL;
    SDL_Surface * sCharge = NULL;
    SDL_Texture * tCharge = NULL;
    initText(sStart, tStart, font, pRenderer, white, "JOUER");*/
    while (isOpen)
    {
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                isOpen = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(events.button.button == SDL_BUTTON_LEFT)
                    if(isOnButton(pquit))
                        isOpen = 0;
                    if(isOnButton(pstart)){
                        isOpen = 0;
                        ret = 1;
                        }
                    if(isOnButton(pcharge)){
                        isOpen = 0;
                        ret = 2;
                    }
                break;
            }
        }

    
        SDL_SetRenderDrawColor(pRenderer, 0,255,0,255);
        SDL_RenderPresent(pRenderer);
    
        initRect(pRenderer, &pstart, 390,195,300,100, 255,0,0);
        initRect(pRenderer, &pcharge, 390,380,300,100, 255,0,0);
        initRect(pRenderer, &pquit, 465,555,150,50, 255,0,0);

        showText(pRenderer, &pstart, "JOUER", font, &white);
        showText(pRenderer, &pquit, "QUITTER", font, &white);
        showText(pRenderer, &pcharge, "CHARGER", font, &white);


        SDL_RenderPresent(pRenderer);
    
    }
    TTF_CloseFont(font);
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);

    TTF_Quit();
    SDL_Quit();
    return ret;
}

void startNewGame(){
    int flags = IMG_INIT_JPG|IMG_INIT_PNG;
    if(IMG_Init(flags))
        printf("GOOD INIT\n");
    SDL_Window* pWindow = NULL ;     
    SDL_Renderer* pRenderer = NULL;

    if (SDL_CreateWindowAndRenderer(LONG, HAUT, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());        
        SDL_Quit();         
    }

    SDL_Texture *pMap = NULL;
    pMap = IMG_LoadTexture(pRenderer, "../asset/map.png");

    SDL_Rect pBottom, pbg, pboutique, prpour, prr, prpoub, prb, ptestslider, pRecMap;
    SDL_Event events;
    int isOpen = 1 ;
    int ret = 0;

    int i = 20 , j = 35;

    pRecMap.x = 100;
    pRecMap.y = 50;
    pRecMap.w = 1080/1.3;
    pRecMap.h = 580/1.3;
    while (isOpen)
    {
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                isOpen = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(events.button.button == SDL_BUTTON_LEFT)
                    if(isOnButton(pboutique)){
                        printf("SHOP \n");
                        shop(pRenderer, pWindow);
                    }
                    if(isOnButton(ptestslider)){

                    }
                break;
            }
        }
    initRect(pRenderer, &pbg, 0,0,LONG,HAUT, 0,137,255);
    SDL_RenderCopy(pRenderer, pMap, NULL, &pRecMap);
    
    initRect(pRenderer, &pBottom, 0,HAUT-180,LONG,200, 91,91,91);

    initRect(pRenderer, &prpour,20 ,HAUT-180+30, 200 , 20 , 255,155,155);
    initRect(pRenderer, &prr,20 ,HAUT-180+30, 2*i , 20 , 240,13,13);

    initRect(pRenderer, &prpoub,20 ,HAUT-180+70, 200 , 20 , 155,155,255);
    initRect(pRenderer, &prb,20 ,HAUT-180+70, 2*j , 20 , 13,13,240);

    initRect(pRenderer, &ptestslider,20 ,HAUT-180+120, 200 , 20 , 155,155,255);

    

    initRect(pRenderer, &pboutique, 1080-100, 720-100, 50,50, 0,0,0);
    SDL_RenderPresent(pRenderer);
    }
    SDL_DestroyTexture(pMap);
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    IMG_Quit();
    SDL_Quit();
}

int shop(SDL_Renderer * Render, SDL_Window * Window){
    SDL_RenderClear(Render);
    SDL_Event events;
    SDL_Rect pQ, pReturn, pItem0,pItem1,pItem2,pItem3,pItem4,pItem5,pItem6,pItem7;
    int isOpen = 1;
    while (isOpen)
    {
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                isOpen = 0;
                return 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(events.button.button == SDL_BUTTON_LEFT)
                    if(isOnButton(pReturn))
                        isOpen = 0;
                    else if(isOnButton(pItem0)){
                        printf("Buyed Item 0 \n");
                        isOpen = 0;
                    }
                    else if(isOnButton(pItem1)){
                        printf("Buyed Item 1 \n");
                        isOpen = 0;
                    }
                    else if(isOnButton(pItem2)){
                        printf("Buyed Item 2 \n");
                        isOpen = 0;
                    }
                    else if(isOnButton(pItem3)){
                        printf("Buyed Item 3 \n");
                        isOpen = 0;
                    }
                break;
            }
        }
    initRect(Render, &pQ, 0,0,LONG,HAUT, 0,137,255);
    initRect(Render, &pItem0, 136, 80,100,100, 118,118,118);
    initRect(Render, &pItem1, 372, 80,100,100, 118,118,118);
    initRect(Render, &pItem2, 608, 80,100,100, 118,118,118);
    initRect(Render, &pItem3, 844, 80,100,100, 118,118,118);

    initRect(Render, &pItem4, 136, 280,100,100, 118,118,118);
    initRect(Render, &pItem5, 372, 280,100,100, 118,118,118);
    initRect(Render, &pItem6, 608, 280,100,100, 118,118,118);
    initRect(Render, &pItem7, 844, 280,100,100, 118,118,118);


    initRect(Render, &pReturn, 1080-70, 720-70, 50,50, 255,0,0);
    SDL_RenderPresent(Render);
    }
    return 1;
}
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


void initText(SDL_Surface * surface, SDL_Texture * texture, TTF_Font * font, SDL_Renderer * render, SDL_Color color ,char * text){
    surface = TTF_RenderText_Blended(font , text, color);
    texture = SDL_CreateTextureFromSurface(render, surface);
}

void initRect(SDL_Renderer * render ,SDL_Rect * rect, int x, int y , int w, int h, int r,int g,int b){
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;

    SDL_SetRenderDrawColor(render, r,g,b,255);
    SDL_RenderFillRect(render, rect);
}

int isOnButton(SDL_Rect rect){
    int x,y;
    SDL_GetMouseState(&x, &y);
    if( (x > rect.x && x < (rect.x+rect.w)) && (y > rect.y && y < (rect.y+rect.h)) )
        return 1;
    return 0;
}
