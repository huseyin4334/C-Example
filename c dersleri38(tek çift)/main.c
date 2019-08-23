#include <stdio.h>
#include <stdlib.h>

int main()
{
int dizi[100];
int cift[100],tek[100];
int i,j=0,k=0;
int adet;
int toplamc=0;
int toplamt=0;
printf("kac adet dizi elemani gireceksiniz:");
scanf("%d",&adet);
for(i=0;i<adet;i++)
{
    printf("%d.sayi:",i+1);
    scanf("%d",&dizi[i]);
    if(dizi[i]%2==0)
    {
        toplamc+=dizi[i];
        cift[j]=dizi[i];
        j++;
    }
    else
    {
        toplamt+=dizi[i];
        tek[k]=dizi[i];
        k++;
    }
}
printf("cift sayilar:");
for(i=0;i<j;i++)
{
    printf("%d ",cift[i]);
}
printf("cift sayilar toplami:%d\n",toplamc);
printf("\ntek sayilar:");
for(i=0;i<k;i++)
{
    printf("%d ",tek[i]);
}
printf("tek sayilar toplami:%d:\n",toplamt);
if(toplamc<toplamt)
    printf("tek sayilarin toplami cift sayilarin toplamindan buyuktur.");
else
    printf("cift sayilarin toplami tek sayilarin toplamindan buyuktur.");
return 0;
}
