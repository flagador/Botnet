/**
 * @file computer.h
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Définition structure computer_t et prototypes fonctions externes
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _COMPUTER_H_
#define _COMPUTER_H_

/**
 * @struct computer_s
 * @brief Structure comprenant les fonctions d'affichage et de destruction, un poids et une puissance
 * 
 */
typedef struct computer_s computer_t;
struct computer_s
{
    void (*afficher)(computer_t * const);
    int (*detruire)(computer_t **);
    int weight;
    int power;

    int status;

};

extern computer_t * computer_create(int weight ,int power, int status);
extern int computer_exist( computer_t * const computer);

#endif