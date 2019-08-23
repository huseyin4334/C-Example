#include <stdio.h>
#include <stdlib.h>
#include<math.h>
void armstrong_sayi()
{
    int i;
    int gecici=0;
    int toplam=0;
    int bas=0;
    int rakam=0;
    for (i=1000;i!=0;i--)
    {
        gecici=i;
        while(gecici!=0)
        {
            gecici/=10;
            bas+=1;
        }
        gecici=i;
        while (gecici!=0)
        {
            rakam=gecici%10;
            gecici/=10;
            toplam+=pow(rakam,bas);
        }
        //printf("%d. egerin toplami %d\n",i,toplam);
        if (i==toplam)
            printf("%d\n",i);
        bas=0;
        toplam=0;
    }
}



int main()
{
    armstrong_sayi();
    return 0;
}
