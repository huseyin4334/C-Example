#include <stdio.h>
#include <stdlib.h>

void sophie_germen()
{
    int i,j;
    int sayi=0;
    int gecici;
    for(i=900;i!=0;i--)
    {
        for(j=2;j<i;j++){
            if(i%j==0)
                sayi=1;
        }
        if(sayi==0)
        {
            gecici=(2*i)+1;
            for(j=2;j<i;j++){
                if(i%j==0)
                    sayi=1;
            }
            if(sayi==0)
                printf("%d asaldir,%d de asaldir.\n",i,gecici);
        }
        sayi=0;
    }
}






int main()
{
    sophie_germen();
    return 0;
}
