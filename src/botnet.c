/**
 * @file botnet.c
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Le fichier botnet.c est le fichier principal, il utilise tous les autres pour éxecuter une partie.
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "../lib/virus.h"
#include "../lib/upgrade.h"
#include "../lib/jeu.h"
#include "../lib/computer_list.h"
#include "../lib/country_list.h"
#include "../lib/config.h"
#include "../lib/data_sdl.h"
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

/**
 * @brief Permet d'afficher la liste de tous les pays, utilise la fonction afficher_country
 * @param cl {Pointeur sur une structure de liste des pays}
*/
void afficher_pays(country_list_t *cl)
{
    for (int i = 0; i < 18; i++)
    {
        afficher_country(cl->liste[i]);
    }
}

void choix(country_list_t *cl, jeu_t *jeu, upgrade_t *upgrade, upgrade_t *cles_usb, upgrade_t *trojan, upgrade_t *fake_ad)
{
    printf(" 1 \n");
    upgrade_display(upgrade);
    printf(" 2 \n");
    upgrade_display(cles_usb);
    printf(" 3 \n");
    upgrade_display(trojan);
    printf(" 4 \n");
    upgrade_display(fake_ad);
    printf(" 5 : Afficher pays \n");
    printf(" 6 : Ne rien faire \n");

    int choix;
    printf("Quel choix voulez vous faire ?");
    scanf("%i", &choix);
    switch (choix)
    {
    case 1:
        buy_upgrade(jeu, upgrade);
        break;
    case 2:
        buy_upgrade(jeu, cles_usb);
        break;
    case 3:
        buy_upgrade(jeu, trojan);
        break;
    case 4:
        buy_upgrade(jeu, fake_ad);
        break;
    case 5:
        afficher_pays(cl);
        break;
    case 6:
        exit;
    default:
        printf("pouet pouet");
    }
}

/**
 * @brief Main 
 * 
 * @return int 
 */
int mainMenu(){
    SDL_Color white = {255,255,255};

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Window* pWindow = NULL;    
    SDL_Renderer* pRenderer = NULL;
    SDL_Rect pstart, pcharge, pquit;
    SDL_Event events;
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
    
        initRect(pRenderer, &pstart, 390,195,300,100, 255,0,0,255);
        initRect(pRenderer, &pcharge, 390,380,300,100, 255,0,0,255);
        initRect(pRenderer, &pquit, 465,555,150,50, 255,0,0,255);

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

int nameVirus(SDL_Renderer * Render, SDL_Window * Window, char ** textaa){
    size_t len = 0;
    size_t l = 0;
    size_t lcp = 0;
    SDL_Color white = {255,255,255};
    SDL_RenderClear(Render);
    SDL_Event events;
    SDL_Rect pQ;
    int isOpen = 1;
    SDL_StartTextInput();
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
                    
                break;
            case SDL_TEXTINPUT:
                l = strlen(events.text.text);
                lcp = len + 1 < MAX_LEN ? 1 : MAX_LEN - len;
                strncpy(*textaa+len, events.text.text, lcp);
                len += lcp;
                printf("%s \n", *textaa);
                break;
            case SDL_KEYDOWN:
                if(events.key.keysym.sym == SDLK_BACKSPACE && len){
                        textaa[0][len -1] = 0;
                        len--;
                        printf("%s \n", *textaa);
                    }else if(events.key.keysym.sym == SDLK_RETURN && len){
                        printf("text : %s \n", *textaa);
                        SDL_StopTextInput();
                        isOpen = 0;
                    }
                break;
            }
        }
    initRect(Render, &pQ, 0,0,LONG,HAUT, 0,137,255,255);
    SDL_RenderPresent(Render);
    }
    return 1;
}


int shop(SDL_Renderer * Render, SDL_Window * Window, jeu_t *jeu, upgrade_t *upgrade, upgrade_t *cles_usb, upgrade_t *trojan, upgrade_t *fake_ad){
    SDL_Color white = {255,255,255};

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
                        buy_upgrade(jeu, upgrade);
                        isOpen = 0;
                    }
                    else if(isOnButton(pItem1)){
                        printf("Buyed Item 1 \n");
                        buy_upgrade(jeu, cles_usb);
                        isOpen = 0;
                    }
                    else if(isOnButton(pItem2)){
                        printf("Buyed Item 2 \n");
                        buy_upgrade(jeu, trojan);
                        isOpen = 0;
                    }
                    else if(isOnButton(pItem3)){
                        printf("Buyed Item 3 \n");
                        buy_upgrade(jeu, fake_ad);
                        isOpen = 0;
                    }
                break;
            }
        }
    initRect(Render, &pQ, 0,0,LONG,HAUT, 0,137,255,255);
    initRect(Render, &pItem0, 136, 80,100,100, 118,118,118,255);
    initRect(Render, &pItem1, 372, 80,100,100, 118,118,118,255);
    initRect(Render, &pItem2, 608, 80,100,100, 118,118,118,255);
    initRect(Render, &pItem3, 844, 80,100,100, 118,118,118,255);

    initRect(Render, &pItem4, 136, 280,100,100, 118,118,118,255);
    initRect(Render, &pItem5, 372, 280,100,100, 118,118,118,255);
    initRect(Render, &pItem6, 608, 280,100,100, 118,118,118,255);
    initRect(Render, &pItem7, 844, 280,100,100, 118,118,118,255);


    initRect(Render, &pReturn, 1080-70, 720-70, 50,50, 255,0,0,255);
    SDL_RenderPresent(Render);
    }
    return 1;
}


void startNewGame(){
    char *VirusName = calloc(MAX_LEN, sizeof(char *));
    /*

    ATTENTION IL VA FALLOIR DETRUIRE VIRUSNAME A LA FIN

    */
    SDL_Color white = {255,255,255};

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
    TTF_Init();

    TTF_Font * font = TTF_OpenFont("../asset/Lato-Black.ttf", 60);
    
    nameVirus(pRenderer, pWindow, &VirusName);
    printf("%s \n", VirusName);
    char buffer [10];
    int result;
    char *buf = malloc(200); 
    result = readlink("/proc/self/exe", buf, 200);

    buf[result] = '\0';
    char *const last = strrchr(buf, '/');
    if (last != NULL)
        *last = '\0';

    chdir(buf);
    free(buf);

    virus_t *virus = virus_create(VirusName, 1, 1);

    printf("K: %s \n", virus->name);

    char WinName[MAX_LEN + 15] = "BotNet : ";
    strcat(WinName, VirusName);
    SDL_SetWindowTitle(pWindow, WinName);
    //virus_display(virus);
    long double *proportion;

    upgrade_t *upgrade = upgrade_create("phishing", 30.0, 0.2, 0.2);
    upgrade_t *cles_usb = upgrade_create("clés usb", 15, 0.1, 0.3);
    upgrade_t *trojan = upgrade_create("trojan", 100.0, 0.5, 0.3);
    upgrade_t *fake_ad = upgrade_create("fake ad", 150, 1.0, 1.0);
    //upgrade_display(upgrade);

    jeu_t *jeu = jeu_create(virus, 200.5);
    virus_display(jeu->virus);

    /* printf("Thunes : %f \n", jeu->btc);
    buy_upgrade(jeu, upgrade);

    virus_display(jeu->virus);
    printf("Thunes : %f \n", jeu->btc);*/

    country_list_t *cl = creer_country_list();

    cl->liste[0]->compromised_pcs_cpt = 10;


    SDL_Texture *pMap = NULL;
    pMap = IMG_LoadTexture(pRenderer, "../asset/map.png");

    SDL_Texture *pBitcoin = NULL;
    pBitcoin = IMG_LoadTexture(pRenderer, "../asset/bitcoin.png");

    SDL_Rect pnext,pBottom,pbg, pmoney,pboutique, prpour, prr, prpoub, prb, pRecMap, pRecBit;
    SDL_Event events;
    int isOpen = 1 ;
    int ret = 0;

    int i = 20 , j = 35;

    pRecMap.x = 100;
    pRecMap.y = 50;
    pRecMap.w = 1080/1.3;
    pRecMap.h = 580/1.3;

    pRecBit.x = 80;
    pRecBit.y = HAUT-180+120;
    pRecBit.w = 20;
    pRecBit.h = 20;

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
                if(events.button.button == SDL_BUTTON_LEFT){
                    if(isOnButton(pboutique)){
                        printf("SHOP \n");
                        shop(pRenderer, pWindow, jeu, upgrade, cles_usb, trojan, fake_ad);
                    }else if(isOnButton(pnext)){
                        spread_world(jeu->virus, cl);
                        mine_btc_world(jeu, cl);
                    }
                }
                break;
            }
        }
    initRect(pRenderer, &pbg, 0,0,LONG,HAUT, 0,137,255,255);
    SDL_RenderCopy(pRenderer, pMap, NULL, &pRecMap);
    
    initRect(pRenderer, &pBottom, 0,HAUT-180,LONG,200, 91,91,91,255);

    initRect(pRenderer, &prpour,20 ,HAUT-180+30, 200 , 20 , 255,155,155,255);
    initRect(pRenderer, &prr,20 ,HAUT-180+30, 2*((int)(compromised_healthy_proportion(cl)*100)) , 20 , 240,13,13,255);
    initRect(pRenderer, &prpoub,20 ,HAUT-180+70, 200 , 20 , 155,155,255,255);
    initRect(pRenderer, &prb,20 ,HAUT-180+70, 2*j , 20 , 13,13,240,255);

    snprintf(buffer , 10, "%.2f", jeu->btc);
    initRect(pRenderer, &pmoney, 20, HAUT-180+120, 50, 20,  91,91,91, 255);
    showText(pRenderer, &pmoney, buffer, font, &white);
    SDL_RenderCopy(pRenderer, pBitcoin, NULL, &pRecBit);

    initRect(pRenderer, &pboutique, 1080-100, 720-100, 50,50, 0,0,0,255);
    initRect(pRenderer, &pnext, 1080-200, 720-100, 50,50, 0,0,0,255);

    SDL_RenderPresent(pRenderer);
    }
    SDL_DestroyTexture(pMap);
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    TTF_CloseFont(font);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
    /*
    while(game_state(jeu, cl)==0)
    {
        printf("-----Thunes----- : %f \n", jeu->btc);
        choix(cl, jeu, upgrade, cles_usb, trojan, fake_ad);
        spread_world(jeu->virus, cl);
        mine_btc_world(jeu, cl);
    }
    if(game_state(jeu, cl)==1){
        printf("Vous avez gagné,wow !");
    } else {
        printf("Vous avez perdu,mince !");
    }

    virus_destroy(&jeu->virus);
    detruire_country_list(&cl);

    return 0;
    */

int main()
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
