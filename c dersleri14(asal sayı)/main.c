#include <stdio.h>
#include <stdlib.h>
int asalsayi(int number1)
{
int i;
    for (i=2;i<number1;i++)
{

    if(number1%i==0)
    {
     return 0;
    }

}
return 1;
}

//
int main()
{
int number;


printf("bir sayi giriniz:");
scanf("%d",&number);
asalsayi(number);
if (asalsayi(number)==0)
{
    printf("%d sayisi asal degildir.\n",number);
}
else
{
printf("%d sayisi asaldir.\n",number);
}
    return 0;
}
