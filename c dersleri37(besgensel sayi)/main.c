#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//besgensel sayi
int f(int sayi)
{
    return sayi*(3*sayi-1)/2;
}



int main()
{
   int i,j,k=1;
   int gecici;
   for(i=1;i<=1000;i++)
   {
       for(j=1;j<i;j++)
       {
           for(k=1;k<i;k++)
           {
                if(f(i)==f(j)+f(k))
                    printf ("f(%d)+f(%d)=f(%d)=%d\n",j,k,i,f(i));
           }
       }
   }
   return 0;
}
