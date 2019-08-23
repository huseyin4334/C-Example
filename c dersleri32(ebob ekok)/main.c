#include <stdio.h>
#include <stdlib.h>

int ebob(int sayi1,int sayi2)
{
    int i;
    int ebo;
    for(i=1;i<=sayi1 && i<=sayi2;i++)
    {
        if(sayi1%i==0 && sayi2%i==0)
           ebo=i;
    }
    return ebo;
}


int ekok(int sayi1,int sayi2)
{
    int i;
    int eko;
    for(i=sayi1*sayi2;i>=sayi1 && i>=sayi2;i--)
    {
        if(i%sayi1==0 && i%sayi2==0)
            eko=i;
    }
    return eko;

}



int main()
{
    int sayi1,sayi2;
    int bolum;
    printf("1.EBOB\n2.EKOK\nseciminiz:");
    scanf("%d",&bolum);
    printf("aralik giriniz:\n");
    scanf("%d %d",&sayi1,&sayi2);
    switch (bolum)
    {
    case 1:
        printf("ebob:%d",ebob(sayi1,sayi2));
        break;
    case 2:
        printf("ekok:%d",ekok(sayi1,sayi2));
        break;
    default:
        printf("yanlis bir ifade girdiniz.");
        break;
    }



}


