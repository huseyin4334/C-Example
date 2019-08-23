#include <stdio.h>
#include <stdlib.h>
int sayi_bul(int bolum)
{
int i,j;
int sayi=0;
for(i=10;;i++)
{
    for(j=1;j<=bolum;j++)
    {
        if(i%j!=0)
        {
            sayi=1;
            continue;}
    }
    if(sayi==0)
        return i;
    else
        sayi=0;

}}
int main()
{
    int a,bolum;
    printf("sayi giriniz:");
    scanf("%d",&bolum);
    a=sayi_bul(bolum);
    printf("%d",a);
    return 0;
}
