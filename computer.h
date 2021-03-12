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
extern int computer_exist(computer_t * const compurer);


