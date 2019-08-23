#include <stdio.h>
#include <stdlib.h>

void tekin_sayi(int sayi,int dizi[],int basamak)
{
    int i,sayac=0;
    for(i=basamak;i!=0;i--)
    {
        if(sayi%dizi[i-1]==0)
            sayac++;
    }
    if(sayac==basamak)
        printf("%d bir tekin sayidir.",sayi);
    else
        printf("%d bir tekin sayi degildir.",sayi);

}


int main()
{
    int number=1,dizi[10];
    int i,j;
    while(number/10==0)
    {
        printf("bir sayi giriniz(tek basamakli sayi girmeyiniz):");
        scanf("%d",&number);
    }
    j=number;
    for (i=0;j!=0;i++)
    {
        dizi[i]=j%10;
        j=j/10;
    }
    tekin_sayi(number,dizi,i);
    return 0;
}
