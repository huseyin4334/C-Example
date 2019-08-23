#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void palindromik_sayi(int sayi)
{
    int i,j;
    int sayac=0;
    int gecici=0;
    int tersi=1;
    gecici+=sayi;
    for (;sayi!=0;)
    {
        sayi=sayi/10;
        sayac++;
    }
    sayi+=gecici;
    for(i=1;sayi>0;i++)
    {
        tersi+=pow(10,sayac-i)*(sayi%10);
        sayi=sayi/10;
    }

    /*printf("%d\n",gecici);
    printf("%d\n",tersi);*/

    if (tersi==gecici)
        printf("%d sayisi bir palindromik sayidir.\n",gecici);

        else
        printf("%d sayisi bir palindromik sayi degildir.\n",gecici);
        printf("%d sayisinin tersi %d'dir.",gecici,tersi);

}
int main()
{
    int number;
    printf("bir sayi giriniz.");
    scanf("%d",&number);
    palindromik_sayi(number);
}
