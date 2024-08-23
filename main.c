#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"
int counter;
cli arr[5];

int main()
{
 int id,id_E,id_R;
 char choice;
 double money;
 while (1)
 {
     printf("Select the operation:\n\n\
1-new client\n\
2-Edit client\n\
3-delete client\n\
4-print data\n\
5-cash transfer\n\
6-Exit\n\n\
Your choice: ");
    fflush(stdin);
    scanf("%c",&choice);
    switch(choice)
    {
    case '1':
        if(counter>=5)
        {
            printf("\n\nYou can't add new client\n");
            break;
        }
        new_client();
        break;
    case '2':
        printf("\n\nEnter the id :\n");
        scanf("%i",&id);
        edit_client(id);
        break;
    case '3':
        printf("\n\nEnter the id :\n");
        scanf("%i",&id);
        delete_client(id);
        break;
    case '4':
        printf("\n\nEnter the id :\n");
        scanf("%i",&id);
        print_data(id);
        break;
    case '5':
        printf("\n\nEnter id of the client who money will transfer from his cash:\n");
        scanf("%i",&id_E);
        printf("Enter id of the client who money will transfer to his cash:\n");
        scanf("%i",&id_R);
        printf("Enter the money:\n");
    L1: scanf("%lf",&money);
        if(money<= 0)
        {
            printf("The money must be grater than zero \n");
            goto L1;
        }
        trans_money(id_E,id_R,money);
        break;
    case '6':
        exit(0);
    default:
        printf("\n\nWrong choice\n");
    }
 }
    return 0;
}
