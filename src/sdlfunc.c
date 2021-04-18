/**
 * @file sdlfunc.c
 * @author {Klemens Galus}
 * @brief Bibliothèque d'aides pour la sdl
 * @version 0.1
 * @date 2021-04-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../lib/data_sdl.h"
#include "../lib/country_list.h"
#include "../lib/config.h"
#include <unistd.h>
#include <stdio.h>

void showText(SDL_Renderer *render, SDL_Rect *rect, const char *text, TTF_Font *font, SDL_Color *color)
{
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
    SDL_RenderCopy(render, texture, NULL, &message_rect);
    SDL_DestroyTexture(texture);
}
void showSmallerText(SDL_Renderer *render, SDL_Rect *rect, const char *text, TTF_Font *font, SDL_Color *color, int y)
{
    SDL_Surface *surface;
    SDL_Texture *texture;

    surface = TTF_RenderText_Solid(font, text, *color);
    texture = SDL_CreateTextureFromSurface(render, surface);

    SDL_Rect message_rect;
    message_rect.x = rect->x;
    message_rect.y = y;
    message_rect.w = rect->w;
    message_rect.h = rect->h / 4;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render, texture, NULL, &message_rect);
    SDL_DestroyTexture(texture);
}

/*
void initText(SDL_Surface * surface, SDL_Texture * texture, TTF_Font * font, SDL_Renderer * render, SDL_Color color ,char * text){
    surface = TTF_RenderText_Blended(font , text, color);
    texture = SDL_CreateTextureFromSurface(render, surface);
}*/
/**
 * @brief Crée un rectangle
 * 
 * @param render objet de rendu
 * @param rect objet rectangle
 * @param x pos x du coin supérieur gauche
 * @param y pos y du coin supérieur gauche
 * @param w largeur
 * @param h hauteur
 * @param r canal couleur rouge
 * @param g canal couleur vert
 * @param b canal couleur bleu
 * @param alpha tranparence
 */
void initRect(SDL_Renderer *render, SDL_Rect *rect, int x, int y, int w, int h, int r, int g, int b, int alpha)
{
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;

    SDL_SetRenderDrawColor(render, r, g, b, alpha);
    SDL_RenderFillRect(render, rect);
}

/**
 * @brief Test si un clic est sur un bouton
 * 
 * @param rect Bouton à tester
 * @return int 1 si le clic est sur le bouton, 0 sinon
 */
int isOnButton(SDL_Rect rect)
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    //printf("x = %i , y = %i \n", x,y);
    if ((x > rect.x && x < (rect.x + rect.w)) && (y > rect.y && y < (rect.y + rect.h)))
        return 1;
    return 0;
    //return (x > rect.x && x < (rect.x + rect.w)) && (y > rect.y && y < (rect.y + rect.h));
}

/**
 * @brief Dessine un cercle
 * 
 * @param renderer 
 * @param x 
 * @param y 
 * @param radius 
 * @return int 
 */
int SDL_RenderDrawCircle(SDL_Renderer *renderer, int x, int y, int radius)
{
    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = radius;
    d = radius - 1;
    status = 0;

    while (offsety >= offsetx)
    {
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y - offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y - offsetx);

        if (status < 0)
        {
            status = -1;
            break;
        }

        if (d >= 2 * offsetx)
        {
            d -= 2 * offsetx + 1;
            offsetx += 1;
        }
        else if (d < 2 * (radius - offsety))
        {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else
        {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}

/**
 * @brief Dessine un disque
 * 
 * @param renderer 
 * @param x 
 * @param y 
 * @param radius 
 * @return int 
 */
int SDL_RenderFillCircle(SDL_Renderer *renderer, int x, int y, int radius)
{
    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = radius;
    d = radius - 1;
    status = 0;

    while (offsety >= offsetx)
    {

        status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx, x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety, x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety, x + offsetx, y - offsety);
        status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx, x + offsety, y - offsetx);

        if (status < 0)
        {
            status = -1;
            break;
        }

        if (d >= 2 * offsetx)
        {
            d -= 2 * offsetx + 1;
            offsetx += 1;
        }
        else if (d < 2 * (radius - offsety))
        {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else
        {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}

/**
 * @brief Modifie la transparence de l'image "infectée" selon l'infection des pays
 * 
 * @param cl 
 * @param textures 
 */
void drawCountryPoint(country_list_t *cl, texture_list_t *textures)
{
    SDL_SetTextureAlphaMod(/*mapAffC*/ textures->textures[0], cl->liste[5]->compromised_pcs_cpt * 255 / (cl->liste[5]->healthy_pcs_cpt + cl->liste[5]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapAffN*/ textures->textures[1], cl->liste[3]->compromised_pcs_cpt * 255 / (cl->liste[3]->healthy_pcs_cpt + cl->liste[3]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapAffS*/ textures->textures[2], cl->liste[4]->compromised_pcs_cpt * 255 / (cl->liste[4]->healthy_pcs_cpt + cl->liste[4]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapAmeriqueC*/ textures->textures[3], cl->liste[15]->compromised_pcs_cpt * 255 / (cl->liste[15]->healthy_pcs_cpt + cl->liste[15]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapAmeriqueN*/ textures->textures[4], cl->liste[16]->compromised_pcs_cpt * 255 / (cl->liste[16]->healthy_pcs_cpt + cl->liste[16]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapAmeriqueS*/ textures->textures[5], cl->liste[14]->compromised_pcs_cpt * 255 / (cl->liste[14]->healthy_pcs_cpt + cl->liste[14]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapAsie*/ textures->textures[6], cl->liste[10]->compromised_pcs_cpt * 255 / (cl->liste[10]->healthy_pcs_cpt + cl->liste[10]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapBresil*/ textures->textures[7], cl->liste[13]->compromised_pcs_cpt * 255 / (cl->liste[13]->healthy_pcs_cpt + cl->liste[13]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapChine*/ textures->textures[8], cl->liste[8]->compromised_pcs_cpt * 255 / (cl->liste[8]->healthy_pcs_cpt + cl->liste[8]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapCoreN*/ textures->textures[9], cl->liste[9]->compromised_pcs_cpt * 255 / (cl->liste[9]->healthy_pcs_cpt + cl->liste[9]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapCoreS*/ textures->textures[10], cl->liste[17]->compromised_pcs_cpt * 255 / (cl->liste[17]->healthy_pcs_cpt + cl->liste[17]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapEurEs*/ textures->textures[11], cl->liste[1]->compromised_pcs_cpt * 255 / (cl->liste[1]->healthy_pcs_cpt + cl->liste[1]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapEurOu*/ textures->textures[12], cl->liste[0]->compromised_pcs_cpt * 255 / (cl->liste[0]->healthy_pcs_cpt + cl->liste[0]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapInde*/ textures->textures[13], cl->liste[7]->compromised_pcs_cpt * 255 / (cl->liste[7]->healthy_pcs_cpt + cl->liste[7]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapJapon*/ textures->textures[14], cl->liste[11]->compromised_pcs_cpt * 255 / (cl->liste[11]->healthy_pcs_cpt + cl->liste[11]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapMoyO*/ textures->textures[15], cl->liste[6]->compromised_pcs_cpt * 255 / (cl->liste[6]->healthy_pcs_cpt + cl->liste[6]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapOceanie*/ textures->textures[16], cl->liste[12]->compromised_pcs_cpt * 255 / (cl->liste[12]->healthy_pcs_cpt + cl->liste[12]->compromised_pcs_cpt));
    SDL_SetTextureAlphaMod(/*mapRussie*/ textures->textures[17], cl->liste[2]->compromised_pcs_cpt * 255 / (cl->liste[2]->healthy_pcs_cpt + cl->liste[2]->compromised_pcs_cpt));
}

/**
 * @brief Récupère les textures dans un fichier donc chaque ligne est au format : <chemin>\n
 * 
 * @param render 
 * @param fichierloc Fichier contenant les textures
 * @return texture_list_t* 
 */
texture_list_t *creer_texture_list(SDL_Renderer *render, char fichierloc[25])
{
    FILE *fichier;
    int read;
    int nblignes = compter_lignes(fichierloc);


    fichier = fopen(fichierloc, "r");
    printf("Nombre de textures : %i \n", nblignes + 1);
    texture_list_t *texture_list = malloc(sizeof(texture_list_t));

    texture_list->textures = malloc(sizeof(texture_list_t) * nblignes);
    texture_list->nb = nblignes;
    int i = 0;
    char passTexture[40];
    SDL_Texture *texture = NULL;

    while (read = fscanf(fichier, "%[^\n]\n", passTexture) != EOF)
    {
        printf("passTexture : %s \n", passTexture);
        texture = IMG_LoadTexture(render, passTexture);
        printf("%p \n", texture);
        texture_list->textures[i] = texture;
        i++;
    }
    printf("I : %d\n", i);
    fclose(fichier);
    return texture_list;
}
/**
 * @brief Supprime les textures et libère la pile
 * 
 * @param texture 
 */
void destroyTexture(texture_list_t **texture)
{
    int i;
    for (i = 0; i < (*texture)->nb; i++)
    {
        SDL_DestroyTexture((*texture)->textures[i]);
    }
    free((*texture)->textures);
    free((*texture));
}

/**
 * @brief Génère les boutons du shop en fonction des upgrades
 * 
 * @param Items 
 * @param Render 
 * @param up_list 
 * @param font 
 */
void genererShop(SDL_Rect *Items, SDL_Renderer * Render, upgrade_list_t * up_list, TTF_Font *font)
{
    SDL_Color white = {255, 255, 255};
    char buffer[50];
    int index, posX, posY, ligne = 0, colone = 0;
    int nbMax = up_list->nb <= 8 ? up_list->nb : 8;
    for (index = 0; index < nbMax; index++)
    {
        initRect(Render, &Items[index], 136 + (100 * colone) + (136 * colone), 80 + 200 * (ligne), 150, 150, 118, 118, 118, 255);
        snprintf(buffer, 50, "%s", up_list->liste[index]->name);
        showSmallerText(Render, &Items[index], buffer, font, &white, Items[index].y);
        snprintf(buffer, 50, "Prix:%.2f", up_list->liste[index]->price);
        showSmallerText(Render, &Items[index], buffer, font, &white, Items[index].y + 30);
        snprintf(buffer, 50, "Propagation:%.2f", up_list->liste[index]->spreading_rate);
        showSmallerText(Render, &Items[index], buffer, font, &white, Items[index].y + 60);
        snprintf(buffer, 50, "Recherche:%.2f", up_list->liste[index]->research_rate);
        showSmallerText(Render, &Items[index], buffer, font, &white, Items[index].y + 90);
        colone++; 
        if (colone == 4)
        {
            colone = 0; //colone = colone%5;
            ligne++; //ligne = colone == 0 ? ligne + 1 : ligne;
        }
    }
}