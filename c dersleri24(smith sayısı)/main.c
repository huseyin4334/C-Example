#include <stdio.h>
#include <stdlib.h>

void smith_sayi(int sayi)
{
    int i;
    int bolenler=0;
    int rakam_toplam=0;
    int gecici=0;
    int gecici1=0;
   gecici1+=sayi;
   for (i=10;sayi!=0;)
   {
       rakam_toplam+=sayi%10;
       sayi=sayi/i;
   }
    sayi+=gecici1;


    for (i=2;sayi/i!=0;i++)
   {
       while(i*(sayi/i)==sayi)
       {
            sayi=sayi/i;
            if(i/10!=0)
            {
                gecici+=i;
                while(i!=0)
                {
                    bolenler+=i%10;
                    i=i/10;
                }

            }
            else
                bolenler+=i;
            i+=gecici;
            gecici=0;


       }

   }
   if (rakam_toplam==bolenler)
      printf("%d bir smith sayisidir.",gecici1);
}

int main()
{
    int sayi;
    printf("bir sayi giriniz:");
    scanf("%d",&sayi);
    smith_sayi(sayi);
}
