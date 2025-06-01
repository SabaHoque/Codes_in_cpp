#include<stdio.h>
#include<string.h>
#include<ctype.h>
int show_menu(int);
int order(int);
int add(int);
int main()

{
    char y[10];
    int k;
    char f[4]="No";
    printf("WELCOME TO OUR RESTURANT!!\n");
    show_menu(2);
    order(1);
    printf("\nSir/Mam,Do you want to order anything else? \n");
    for(k=0; k<1; k++)
    {
        scanf("%s",&y[k]);
    }
    if(y[k]==f[k])
    {
        for(k=0; k<1; k++)
        {
            printf("Ok,Sir/Mam.");
            break;
        }
    }
        else
        {
            printf("What do you want to order?");
            add(3);
        }
        printf("\nTHANKYOU SIR/MAM.");
        printf("\nPlease wait.Your order will come in 20 mintues.");


    }

    int show_menu(int x)
    {
        printf("-----------------------------------------------------------------");
    printf("\n----------------------- Here is our menu ------------------------\n");
    printf("-----------------------------------------------------------------\n");

    char item1[100]="0. Burger with fries -------------------------------- Price-550tk";
    char item2[100]="1. Pizza -------------------------------------------- Price-450tk";
    char item3[100]="2. fries -------------------------------------------- Price-150tk";
    char item4[100]="3. Noddles ------------------------------------------ Price-250tk";
    char item5[100]="4. chicken fry -------------------------------------- Price-200tk";
    char item6[100]="5. Pasta -------------------------------------------- Price-300tk";
    char item7[100]="6. fried rice --------------------------------------- Price-270tk";
    char item8[100]="7. cola --------------------------------------------- Price-50tk";
    char item9[100]="8. cold coffee -------------------------------------- Price-170tk";
    char item10[100]="9. pastry ------------------------------------------- Price-1800tk";

        printf("\n%s \n%s \n%s \n%s \n%s \n%s \n%s \n%s \n%s \n%s\n",item1,item2,item3,item4,item5,item6,item7,item8,item9,item10);
        printf("\n----------- What do you want to order? -----------------");
    }
    int order(int n)
    {
        int i;
        printf("\nEnter your order number : ");
        int price[10]= {550,450,150,250,200,300,270,50,170,180};
        scanf("%d",&n);
        for(i=0; i<10; i++)
        {
            if(i==n)
            {
                printf(" price %d tk",price[i]);
            }
        }
    }

    int add(int x)
    {
        int j;
        printf("Enter your order number : ");
        int price[10]= {550,450,150,250,200,300,270,50,170,180};
        scanf("%d",&x);
        for(j=0; j<10; j++)
        {
            if(j==x)
            {
                printf(" price %d tk",price[j]);
            }
        }
    }
