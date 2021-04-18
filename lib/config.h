/**
 * @file config.h
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Fichier de configuration, permet d'équilibrer le jeu
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#define DEFAULT_BITCOIN 100
#define DEFAULT_BOTNET_SIZE 10
#define DEFAULT_MINING_RATE 0.5
#define DEFAULT_SPREADING_RATE 1
#define DEFAULT_RESEARCH_RATE 1
#define DEFAULT_INFECTED_COUNTRY 2

#define WIN_PROPORTION 0.51

#define BOTNET_BORDER_LEAK 0.05 //chances max qu'une fuite se produise à la frontière
#define BOTNET_EXPENSION_MEDIANE 0.2 //X * corrupted PCs
#define BOTNET_EXPENSION_ECART_TYPE 0.2 //X fois la médiane
#define BITCOIN_MINING_COEFFICIENT 0.05

#define MAX_LEN 20 //Taille MAX du nom du virus

extern int compter_lignes(char *n_fichier);
