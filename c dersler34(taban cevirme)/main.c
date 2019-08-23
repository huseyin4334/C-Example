#include <stdio.h>
#include <stdlib.h>

void taban(int sayi,int cevir)
{
    int i,j;
    int dizi[100];
    for (i=0;sayi!=0;i++)
    {
        dizi[i]=sayi%cevir;
        sayi=sayi/cevir;
    }
    for(j=i-1;j>=0;j--)
        printf("%d",dizi[j]);

}






int main()
{
    int sayi,cevir;
    printf("cevirmek istediginiz sayiyi giriniz:");
    scanf("%d",&sayi);
    printf("cevirmek istediginiz tabani giriniz:");
    scanf("%d",&cevir);
    taban(sayi,cevir);
    return 0;
}
