#include <stdio.h>
#include <stdlib.h>

void fib(int sayi)
{
    int i;
    int dizi[100];
    dizi[0]=0;
    dizi[1]=1;
    for (i=2;i<sayi;i++)
    {
        dizi[i]=dizi[i-1]+dizi[i-2];
    }
    for (i=0;i<sayi;i++)
    {
        printf("%d ",dizi[i]);
    }
}





int main()
{
    int sayi;
    printf("bir sayi giriniz:");
    scanf("%d",&sayi);
    fib(sayi);
    /*int ilksayi=1;
    int ikincisayi=1;
    int i,a;

    printf("\nkacin fibonacci degerini istersiniz:");
    scanf("%d",&a);
    printf("%d\n%d\n",ilksayi,ikincisayi);
    for(i=0;i<a;i++)
    {
        int temp=ikincisayi;

        ikincisayi+=ilksayi;

        ilksayi=temp;

        printf("%d\n",ikincisayi);
    }*/
    return 0;
}
