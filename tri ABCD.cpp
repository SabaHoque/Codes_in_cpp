/*  A
    B
    A B C
    A B C D
    A B C D E  */

#include<stdio.h>
int main()
{
    char i,j;
    for(i=5; i>=1; i--)
    {
        for(j=1; j<=i; j++)
        {
            printf(" %d",i);
        }
        printf("\n");
    }

  return 0;
}
