#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,sayac=1;
    /*for(j=0;j<3;j++)
    {
        printf("%d",sayac);
    for(i=1;i<=10;i++)
    {

        if(i%sayac==0)
            printf("%d",i);
    }
    printf("\n");
    sayac++;
    }*/
    for(i=1;i<6;i++)
    {
        for(j=1;j<6;j++)
        {
            sayac*=i;
        }
        printf("%d\n",sayac);
        sayac=1;
    }

    return 0;
}
