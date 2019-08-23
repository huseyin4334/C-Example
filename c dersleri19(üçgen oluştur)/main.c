#include <stdio.h>
#include <stdlib.h>
void ust_ucgen(int sayi)
{
    int i,j;
    for (i=1;i<=sayi;i++)
        {
        for (j=1;j<=i;j++)
    {
        printf("X");
    }
    printf("\n");
    }
}
void alt_ucgen(int sayi)
{
    int i,j;
    for (i=1;i<=sayi;i++)
        {
        for (j=1;j<=sayi-i;j++)
    {
        printf("X");
    }
    printf("\n");
    }
}

int main()
{int number;
printf("bir sayi giriniz:");
scanf("%d",&number);
ust_ucgen(number);
alt_ucgen(number);
    return 0;
}
