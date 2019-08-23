#include <stdio.h>
#include <stdlib.h>

//üçgen hesaplama

int main()
{
int sec1,kose1,kose2,kose3,sonuc;

printf("dortgenlerde hacim hesaplama programina hos geldiniz.\n");
printf("1-)kup\n2-)dortgen\n seciminiz:");
scanf("%d",&sec1);
  if (sec1==1)
  {
     printf("köse uzunlugu:");
     scanf("%d",&kose1);
     sonuc=kose1*kose1*kose1;
     printf("kupun hacmi:%d",sonuc);

  }
  else if (sec1==2)
  {
     printf("1.kose uzunlugu:");
     scanf("%d",&kose1);
     printf("2.kose uzunlugu:");
     scanf("%d",&kose2);
     printf("3.kose uzunlugu:");
     scanf("%d",&kose3);
     sonuc=kose1*kose2*kose3;
     printf("dorgenin hacmi:%d",sonuc);

  }
  else
  {
   printf("yanlis deger girdiniz.");
  }


  return 0;
}
