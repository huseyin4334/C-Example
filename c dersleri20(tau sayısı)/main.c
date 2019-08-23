#include <stdio.h>
#include <stdlib.h>

int tau_sayisi(int sayi)
{
    int bolen=0;
    int i;
    for(i=1;i<=sayi;i++)
    {
        if (sayi%i==0)
        {
            bolen++;
        }

    }
    return bolen;
}
int main()
{
    int sayi;
    printf("bir sayi giriniz:");
    scanf("%d",&sayi);
    if (sayi/tau_sayisi(sayi)==0)
        printf("%d bir tau sayisidir.",sayi);
    else
        printf("%d bir tau sayisi degildir.",sayi);


    return 0;
}
