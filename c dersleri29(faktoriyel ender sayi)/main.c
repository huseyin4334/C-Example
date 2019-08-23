#include <stdio.h>
#include <stdlib.h>

void fak()
{
    int i,j;
    int gecici;
    int fac=1;
    int rakam;
    int toplam=0;
    for (i=145;i!=0;i--)
    {
        gecici=i;
        while(gecici!=0)
        {
            rakam=gecici%10;
            for(j=1;j<=rakam;j++)
            {
                fac*=j;
            }
            toplam+=fac;
            fac=1;
            gecici/=10;


        }
        printf("%d\n",toplam);
        if (toplam==i)
        {
            printf("%d ender bir sayidir.\n",i);
        }
        toplam=0;

    }
}




int main()
{
    fak();

    return 0;
}
