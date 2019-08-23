#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi,i,j,a=0;
    printf("bir sayi giriniz:");
    scanf("%d",&sayi);
    for(i=sayi+1;;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                a=1;
                break;
            }
        }
        if(a==0)
        {
            printf("%d sayisina en yakin asal sayi %d'dir.",sayi,i);
            break;
        }
        else
            a=0;
    }
    return 0;
}
