#include <stdio.h>
#include <stdlib.h>

void sirala(int A[],int B[],int C[],int a,int b)
{

   //int dizi[8]={1,4,6,7,9,12,34,42};
    //int dizi1[5]={2,5,8,13,56};

    int i,j;
    int xi=0,yi=0;
    for(i=0;i<a+b;i++)
    {
        if(A[xi]>B[yi])
        {
            C[i]=B[yi];
            yi++;
        }
        else
        {
            C[i]=A[xi];
            xi++;
        }
        if(xi==a || yi==b)
            break;

    }
    if (xi==a)
    {
        for(j=i+1;j<a+b;j++)
        {
            C[j]=B[yi];
            yi++;
        }
    }
    else
    {
        for(j=i+1;j<a+b;j++)
        {
            C[j]=A[xi];
            xi++;
        }
    }





 for(i=0;i<13;i++)
 {
     printf("%d ",C[i]);
 }

}








int main()
{
    int dizi[8]={1,4,6,7,9,12,34,42};
    int dizi1[5]={2,5,8,13,56};
    int toplam[13];
    sirala(dizi,dizi1,toplam,8,5);
    return 0;
}
