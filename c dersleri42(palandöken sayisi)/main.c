#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void palandoken()
{
    int i,j,k;
    int gecici;
    int dizi[10];
    int sayi=0;
    int a=10;
    int us;
    int tutucu;
    int toplam=0,sayac=0;
    for(i=900;i>9;i--)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {                                  //asallýk kontrolü yapar tüm sayilar için
                sayi=1;
                break;
            }
        }
        if(sayi==0)                           //asal olan sayýlar buraya girer
        {
            gecici=i;
            for(j=0;gecici!=0;j++)
            {
                gecici=gecici/10;            //sayýnýn basamak sayýsýný belirler
            }
            gecici=i;
            for(k=0;gecici!=0;k++)
            {
                us=pow(10,j-k-1);
                if(us==99)
                    us=100;
                tutucu=gecici%us;
                dizi[k]=gecici/us;              //sayýyý elemanlarýna ayýrýr
                if(us==1)
                    tutucu=0;
                gecici=tutucu;
            }
            if(j==3)                 //eleman sayýsý üçse buraya girer
            {
                for(j=0;j<3;j++)
                {
                    for(k=0;k<3;k++)
                    {
                        if(j==k)
                        {
                            continue;                  //sayýnýn olasýlýklarýný dener
                        }
                        toplam+=dizi[k]*a;
                        a=a/10;
                    }
                    for(k=2;k<toplam;k++)
                    {
                        if(toplam%k==0)
                        {
                            sayi=1;                    //sayýnýn olasýlýklarýnýn asallýðýný kontrol eder
                            break;
                        }
                    }
                    if(sayi==0)
                        sayac++;
                    sayi=0;
                    toplam=0;                               //sayý asalsa sayaç artar sayac 3 ise kural saðlanýr
                    a=10;
                }
                if(sayac==3)
                    printf("%d bir palandoken sayidir.\n",i);
            }
            else if(j==2)
            {
                for(j=0;j<2;j++)
                {
                    for(k=0;k<2;k++)
                    {
                        if(j==k)
                            continue;
                        toplam+=dizi[k];
                    }
                    for(k=2;k<toplam;k++)
                    {
                        if(toplam%k==0)
                        {
                            sayi=1;
                            break;
                        }
                    }
                    if(sayi==0 && toplam!=1)
                        sayac++;
                    sayi=0;
                    toplam=0;
                }
                if(sayac==2)
                    printf("%d bir palandoken sayidir.\n",i);
            }
        }
        sayi=0;
        sayac=0;
        a=10;
    }
}
int main()
{
    palandoken();
    return 0;
}
