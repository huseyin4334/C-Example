#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
ax^2+bx+c þeklindeki bir denklem için;
*/

int main()
{
    int a,b,c,delta;
    float x1,x2;

    printf("denklemin a,b ve c degerlerini giriniz.\n");
    printf("denlemin a'sini giriniz:");
    scanf("%d",&a);
    printf("denlemin b'sini giriniz:");
    scanf("%d",&b);
    printf("denlemin c'sini giriniz:");
    scanf("%d",&c);
    delta=b*b-(4*a*c);
    if (delta>0)
    {
        printf("denlemin iki koku vardir.\n");
        x1=-b+(sqrt(delta))/2*a;
        x2=-b-(sqrt(delta))/2*a;
        printf("x1:%f\nx2:%f",x1,x2);
    }
    else if(delta==0)
    {
        printf("denlemin bir koku vardir.\n");
        x1=-b+(sqrt(delta))/2*a;
        printf("x1:%f",x1);
    }
    else
    {
        printf("denlemin koku yoktur.\n");
    }


    return 0;
}
