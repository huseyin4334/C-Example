#include <stdio.h>
#include <stdlib.h>

void ozel()
{
    int i,j;
    int gecici;
    int kare;
    int toplam=0;
    for (i=100;i!=0;i--)
    {
        kare=i*i;
        gecici=kare;

        /*if (i<1000 || i>99)
        {
            for(j=0;j<1;j++)
            {
                gecici=gecici%1000;
            }
        }*/
        if (i<100 || i>9)
        {
            for(j=0;j<1;j++)
            {
                gecici=gecici%100;
            }
        }
        else
        {
            for(j=0;j<1;j++)
            {
                gecici=gecici%10;
            }
        }
        if (gecici==i)
        {
            printf("%d bir ozel sayidir ve karesi %d'dir.\n",i,kare);
            toplam+=i;
        }
    }
     printf("bunlarin toplami %d'dir.\n",toplam);

}



int main()
{
    ozel();
    return 0;
}
