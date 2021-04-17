#include "../lib/upgrade_list.h"

#include <stdio.h>
int main()
{
    upgrade_list_t * l = upgrade_liste_creer(8);

    printf("upgrade_list créée\n");

    upgrade_t *phishing = upgrade_create("phishing", 200, 0.01, 0.03);
    upgrade_t *cles_usb = upgrade_create("cles usb", 500, 0.01, 0.02);
    upgrade_t *trojan = upgrade_create("trojan", 1000, 0.03, 0.04);
    upgrade_t *fake_ad = upgrade_create("fake ad", 10000, 0.0, -0.01);
    upgrade_t *backdoor = upgrade_create("backdoor", 20000, 0.1, 0.3);
    upgrade_t *boot_sector = upgrade_create("boot sector", 50000, 0.1, 0.2);
    upgrade_t *spyware = upgrade_create("spyware", 100000, 0.3, 0.4);
    upgrade_t *polymorphic = upgrade_create("polymorphic virus", 500000, 0.0, -0.1);

    printf("upgrades créées\n");


    l->liste[0] = phishing; 
    l->liste[1] = cles_usb; 
    l->liste[2] = trojan; 
    l->liste[3] = fake_ad; 
    l->liste[4] = backdoor; 
    l->liste[5] = boot_sector; 
    l->liste[6] = spyware; 
    l->liste[7] = polymorphic; 

    printf("upgrades insérées\n");

    printf("upgrade list : \n");

    afficher_upgrade_list(l);

    upgrade_liste_sauv(l, "../datas/upgrade.save"); //changer le nom du fichier si besoin
    

    upgrade_liste_destroy(&l);
}