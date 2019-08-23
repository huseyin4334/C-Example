#include <stdio.h>
#include <stdlib.h>
//dengeli sayi
int main()
{
    int i,j,tut;
    int tek=0,cift=0;
    for(i=10000;i!=9;i--)
    {
        tut=i;
        while(tut!=0)
        {
            j=tut%10;
            if(j%2==0)
                cift++;
            else
                tek++;
            tut=tut/10;
        }
        if(tek==cift)
            printf("%d bir dengeli sayidir.\n",i);
        tek=0;
        cift=0;
    }

    return 0;
}
