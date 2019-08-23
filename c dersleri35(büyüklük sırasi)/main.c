#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j=0;
    int dizi[100];
    int sira[100];
    int adet;
    int gecici;
    int sayac=1;
    printf("kac adetlik bir dizi:",adet);
    scanf("%d",&adet);
    for(i=0;i<adet;i++)
    {
        printf("%d.sayi:",i+1);
        scanf("%d",&dizi[i]);
    }
    for(i=0;i<adet;i++)
    {
        gecici=dizi[i];
        for(j=0;j<adet;j++)
        {
            if(gecici<dizi[j])
                sayac++;
        }
        sira[i]=sayac;
        sayac=1;
    }
    for(i=0;i<adet;i++)
    {
        printf("%d ",dizi[i]);
    }
    printf("\n");
    for(i=0;i<adet;i++)
    {
        printf("%d ",sira[i]);
    }
    return 0;
}
