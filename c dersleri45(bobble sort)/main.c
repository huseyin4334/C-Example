#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dizi[100];
    int uzunluk,gecici,j,i;
    printf("dizinin uzunlugunu giriniz:");
    scanf("%d",&uzunluk);
    for(i=0;i<uzunluk;i++)
    {
        printf("%d.eleman:",i+1);
        scanf("%d",&dizi[i]);
    }
    printf("\n");
int kontrol=0;
    for(i=0;i<uzunluk;i++)
    {
        for(j=0;j<uzunluk-i-1;j++)
        {
            if(dizi[j]>dizi[j+1])
            {
                gecici=dizi[j];
                dizi[j]=dizi[j+1];
                dizi[j+1]=gecici;
                kontrol=1;
            }
        }
        if(kontrol==0)
            break;
        else
            kontrol=0;
    }
    for(i=0;i<uzunluk;i++)
            {
                printf("%d ",dizi[i]);
            }
    return 0;
}
