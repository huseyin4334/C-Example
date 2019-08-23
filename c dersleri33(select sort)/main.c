#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dizi[1000];
    int i,j,gecici;
    int adet;
    printf("diziniz kac adetten olusacak:");
    scanf("%d",&adet);
    for (i=0;i<adet;i++)
    {
        scanf("%d",&dizi[i]);
    }

    for (i=0;i<adet;i++)
    {
        gecici=i;
        for (j=i+1;j<adet;j++){
            if(dizi[gecici]>dizi[j])
                gecici=j;
            }
        int temp=dizi[i];
        dizi[i]=dizi[gecici];
        dizi[gecici]=temp;
    }
    for (i=0;i<adet;i++){
    printf("%d ",dizi[i]);
    }

    return 0;
}
