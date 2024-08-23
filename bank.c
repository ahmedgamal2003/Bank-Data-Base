#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"
extern int counter;
extern cli arr[5];



void new_client(void)
{
    cli new_c;
    printf("\n\nEnter name of client number %i: ",counter+1);
    fflush(stdin);
    gets(new_c.name);
L1:printf("Enter cash of client number %i: ",counter+1);
    scanf("%lf",&new_c.cash);
    if(new_c.cash<0)
    {
        printf("The cash must be grater than zero try again\n");
        goto L1;
    }
    printf("Type is (debit or credit): ");
    fflush(stdin);
    gets(new_c.type);
    printf("Enter id of the client number %i: ",counter+1);
    scanf("%i",&new_c.id);
    printf("\n\n\n\n\n\n");
    arr[counter]=new_c;
    counter++;
}


void edit_client(int id)
{
    int i;
    for(i=0;i<=counter;i++)
    {
        if(id==arr[i].id)
        {
            printf("\n\nEnter new name: ");
            fflush(stdin);
            gets(arr[i].name);
            printf("Enter new cash: ");
            scanf("%lf",&(arr[i].cash));
            printf("Enter new type (depit or credit): ");
            gets(arr[i].type);
            printf("Enter new id: ");
            scanf("%i",&(arr[i].id));
            printf("\n\n\n\n\n");
            break;
        }
    }
}




void print_data(int id)
{
    int i;
    for(i=0;i<=counter;i++)
    {
        if(arr[i].id==id)
        {
            printf("\n\nName: %s\n",arr[i].name);
            printf("Cash= %.2lf\n",arr[i].cash);
            printf("Type: %s\n",arr[i].type);
            printf("id= %i\n",arr[i].id);
            break;
        }
    }
}


void trans_money(int id_E,int id_R,double mon)
{
    int i,index_from=-1,index_to=-1;
L2: for(i=0;i<=counter;i++)
    {
        if(id_E==arr[i].id)
        {
            index_from=i;
        }
        else if(id_R==arr[i].id)
        {
            index_to=i;
        }
        if(index_from!=-1 && index_to!=-1)
        {
            break;
        }
    }
    if(index_from==-1 || index_to==-1)
    {
        printf("please enter valid id\n");
    }
    if(mon>arr[index_from].cash)
    {
        printf("The money grater than your cash try again\n Enter the money\n");
        scanf("%lf",&mon);
        goto L2;
    }
    arr[index_from].cash=arr[index_from].cash-mon;
    arr[index_to].cash=arr[index_to].cash+mon;

}



void delete_client(int id)
{
    int i,index;
    for(i=0;i<=counter;i++)
    {
        if(id==arr[i].id)
        {
            index=i;
            for(i=index;i<=counter;i++)
            {
                arr[i]=arr[i+1];
            }
        }
    }
    arr[counter].cash=-1;
    arr[counter].id=-1;
    strcpy(arr[counter].name,"-1");
    strcpy(arr[counter].type,"-1");
    counter--;


}
