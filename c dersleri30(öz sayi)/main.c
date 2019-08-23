#include <stdio.h>
#include <stdlib.h>

void oz_sayi(int sayi)
{
    int carpim;
    int i;
    int toplam=0;
    carpim=sayi*9;
    while(carpim!=0)
    {
        toplam+=carpim%10;
        carpim/=10;
    }
    printf("%d'nin oz sayisi %d'dir.",sayi,toplam);


}


int main()
{
    int sayi;
    printf("oz sayisini istediginiz sayiyi giriniz:");
    scanf("%d",&sayi);
    oz_sayi(sayi);

    return 0;
}
