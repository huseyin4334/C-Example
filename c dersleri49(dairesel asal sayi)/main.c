#include <stdio.h>
#include <stdlib.h>

int main()
{
   /* int i,j;
    int number,sayi;
    int dizi[10];
    for(i=999;i!=1;i--)
    {
        for(k=2;k!=i)
        {
            number=i;
            j=0;
            while(number!=0)
            {
                dizi[j]=number%10;
                number=number/10;
                j++;
            }
            if(j==3)
        }

    }*/
    int sayi,tut,buyuk,i=1;
    printf("bir sayi giriniz:");
    scanf("%d",&sayi);
    tut=sayi;
    buyuk=sayi%10;
    sayi=sayi/10;
    if(sayi%10>buyuk)
    {
        buyuk=sayi%10;
        i=10;
    }
    sayi=sayi/10;
    if(sayi%10>buyuk)
    {
        buyuk=sayi%10;
        i=100;
    }
    printf("%d sayisinda en buyuk rakam %d dir.%d ler basamagındadir.",tut,buyuk,i);

    return 0;
}
