#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


void menu();
float lunchdinner();
float breakfast();
float kid();
float promotion();
float drink();
float frenchfries();
float dessert();
float total();
float totaldinein();
float totaltakeout();
void  login();


int x,r,t,w,z;
float land ,land1, buff ,kidd ,pro ,din ,fren ,dess ;
float total1;

main()
{
    printf("----------------------------------------------------------\n");
    printf("          *     Welcome to FRIENDS Restaurant     *       \n");
    printf("----------------------------------------------------------\n");
    printf("\n\n\n\n loading........\n\n\n\n\n\n");
    sleep(3);
    menu();
}


void menu()
{

    int x;

    //Menu
    printf("      PLEASE SELECT AN ITEM FROM THE MENU GIVEN BELOW     \n");
    printf("----------------------------------------------------------\n");
    printf("No.     Items               Price         Detail\n");
    printf("----------------------------------------------------------\n");
    printf("1       Lunch/Dinner Set    TK200.00      1 Chicken curry\n");
    printf("                                          1 Fried rice\n");
    printf("                                          1 drink(medium)\n");
    printf("\n");
    printf("2       Breakfast Set       TK100.00      1 breakfast\n");
    printf("                                          1 drink(medium)\n");
    printf("\n");
    printf("3       Kid Set             TK150.00      1 burger/chicken fry\n");
    printf("                                          1 drink(small)\n");
    printf("                                          1 French fries(small)\n");
    printf("\n");
    printf("4       Promotion           TK100.00      Burger/Chicken\n");
    printf("\n");
    printf("5       Drink               TK30.00       Medium size\n");
    printf("\n");
    printf("6       French Fries        TK80.00       Medium size\n");
    printf("\n");
    printf("7       Dessert             TK100.00      Ice cream/pie/cake\n");
    printf("\n");
    printf("8       Display Total \n");
    printf("\n");
    printf("9       Exit...\n\n");

    printf("\n\nPlease Select Your Option from the Menu : ");
    scanf("%d",&x);



    switch(x)
    {
    case 1: lunchdinner();
            break;

    case 2: breakfast();
            break;

    case 3: kid();
            break;

    case 4: promotion();
            break;

    case 5: drink();
            break;

    case 6: frenchfries();
            break;

    case 7: dessert();
            break;

    case 8: total();
            break;

    case 9: exit(0);

    default: printf("Invalid Error!\n");

    }

}

float lunchdinner()
{



    printf("You have selected Lunch/Dinner Set.");
    printf("\nPlease Enter your Quantity :");
    scanf("%d",&x);

    land=x*200.00;

    printf("Do you want to add-on?(1-Yes, 2-No)");
    scanf("%d",&r);

    if (r==1)
    {   system("cls");                                  //clear screen.
        {menu();}
    }

    else
    {total();}


}

float breakfast()
{



    printf("You have selected Breakfast Set.");
    printf("\nPlease Enter your Quantity :");
    scanf("%d",&x);

    buff = x*100.00;

    printf("Do you want to add-on?(1-Yes, 2-No)");
    scanf("%d",&r);

    if (r==1)
    {   system("cls");
        {menu();}
    }
    else
    {total();}





}
float kid()
{


    printf("You have selected Kiddies Set.");
    printf("\nPlease Enter your Quantity :");
    scanf("%d",&x);

    kidd = x*150.00;

    printf("Do you want to add-on?(1-Yes, 2-No)");
    scanf_s("%d",&r);

    if (r==1)
    {   system("cls");
        {menu();}
    }
    else
    {total();}




}
float promotion()
{


    printf("You have selected Promotion.");
    printf("\nPlease Enter your Quantity :");
    scanf("%d",&x);

    pro = x*100.00;

    printf("Do you want to add-on?(1-Yes, 2-No)");
    scanf_s("%d",&r);

    if (r==1)
    {   system("cls");
        {menu();}
    }
    else
    {total();}




}
float drink()
{


    printf("You have selected to order Drink.");
    printf("\nPlease Enter your Quantity :");
    scanf("%d",&x);

    din = x*30.00;

    printf("Do you want to add-on?(1-Yes, 2-No)");
    scanf("%d",&r);

    if (r==1)
    {   system("cls");
        {menu();}
    }
    else
    {total();}




}
float frenchfries()
{


    printf("You have selected French Fries.");
    printf("\nPlease Enter your Quantity :");
    scanf("%d",&x);

    fren = x*80.00 ;

    printf("Do you want to add-on?(1-Yes, 2-No)");
    scanf_s("%d",&r);

    if (r==1)
    {   system("cls");
        {menu();}
    }
    else
    {total();}




}
float dessert()
{


    printf("You have selected Dessert.");
    printf("\nPlease Enter your Quantity :");
    scanf("%d",&x);

    dess = x*100.00 ;

    printf("Do you want to add-on?(1-Yes, 2-No)");
    scanf_s("%d",&r);

    if (r==1)
    {   system("cls");
        {menu();}
    }
    else
    {total();}






}



float total()                                                           //Food Menu Calculations.
{
    printf("Do you want to dine in or take away?\n");
    printf("1) Dine In 2) Take Away\n");
    scanf("%d",&w);

    switch(w)

    {
    case 1: totaldinein();
            break;

    case 2: totaltakeout();
            break;

    default: system("cls");
             printf("\n\nInvalid Error!\n");
    }



}


float totaldinein()                                                         //This function is to calculate the total price of DINING IN including the 5% government tax and 10% dining in charges.


{
    system("cls");
    printf("Select your payment method:1--> Cash Payment     2--> Credit Card Payment\n");
    scanf("%d",&t);

    switch (t)
    {
    case 1: total1 += (land + buff + kidd + pro + din + fren + dess)*1.15;                   //Calculation for grand total with taxes,and cash payment.

            printf("\nThe Total is taka %.2f\n\n",total1);
            printf("THANK YOU FOR FOR CHOOSING OUR RESTAURANT\n\n\n");

            break;

    case 2: total1 += (land + buff + kidd + pro + din + fren + dess)*1.18;                   //Calculation for grand total with taxes,and credit card payment.

            printf("\nThe Total is taka %.2f\n\n",total1);
            printf("THANK YOU FOR FOR CHOOSING OUR RESTAURANT\n\n\n");

            break;

    default: system("cls");
             printf("\nInvalid Error");
    }




}

float totaltakeout()                                                        //This function is to calculate the  total price of TAKE AWAY including the 5% government tax and 5% dining in charges.

{
    system("cls");
    printf("Select your payment method:1--> Cash Payment     2--> Credit Card Payment\n");
    scanf("%d",&t);

    switch (t)
    {
        case 1: total1 += (land + buff + kidd + pro + din + fren + dess)*1.10;               //Calculation for grand total with taxes,and cash payment.

                printf("The Total is taka %.2f\n\n",total1);
                printf("THANK YOU FOR FOR CHOOSING OUR RESTAURANT\n\n\n");

                break;

        case 2: total1 += (land + buff + kidd + pro + din + fren + dess)*1.13;               //Calculation for grand total with taxes,and credit card payment.

                printf("The Total is taka %.2f\n\n",total1);
                printf("THANK YOU FOR FOR CHOOSING OUR RESTAURANT\n\n\n");

                break;

        default: system("cls");
                 printf("\nInvalid Error");

    }
}
