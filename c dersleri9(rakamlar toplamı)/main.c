#include <stdio.h>
#include <stdlib.h>
//bir sayinin basamak ve rakamalri toplami
int main()
{
    int sayi,hane=0,toplam=0;

    printf("bir sayi soyleyin:");
    scanf("%d",&sayi);

    do
    {
        toplam+=(sayi%10);

        hane++;
        sayi=sayi/10;

    }
    while(sayi>0);
    {
        printf("verdiginiz sayinin rakamlar toplami %d.\n sayi %d hanelidir.",toplam,hane);
    }
    return 0;
}
