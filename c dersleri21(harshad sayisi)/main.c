#include <stdio.h>
#include <stdlib.h>

int harshad_sayisi(int sayi)
{
    int i;
    int toplam=0;
    for (i=1;sayi!=0;)
    {
        sayi=sayi/10;
        toplam+=sayi%10;
    }
    return toplam;
}
int main()
{
    int sayi;
    printf("bir sayi giriniz:");
    scanf("%d",&sayi);
    if (sayi%harshad_sayisi(sayi)==0)
        printf("%d sayisi harshad sayisidir.",sayi);
    else
        printf("%d sayisi harshad sayisi degildir.",sayi);
    return 0;
}
