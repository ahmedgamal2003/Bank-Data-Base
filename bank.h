#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct client
{
    char name[30];
    double cash;
    char type[7];
    int id;
} cli;

void new_client(void);
void edit_client(int id);
void print_data(int id);
void trans_money(int id_E,int id_R,double mon);
void delete_client(int id);
