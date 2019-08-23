#include <stdio.h>
#include <stdlib.h>
#include<math.h>
void ender_sayi()
{
int i,j;
int gecici;
int gecici1=0;
int sayi_kare;
int sayi_ters=0;
int a=0;
int ters_kare;
int adet=0;
for (i=100;i!=0;i--)
{
    sayi_kare=i*i;



    gecici=i;
    while(i!=0)
    {
        i=i/10;
        a+=1;
    }
    i=gecici;


    for(j=1;i!=0;j++)
    {
        sayi_ters+=pow(10,a-j)*(i%10);
        i=i/10;

    }
    i=gecici;
    a=0;
    ters_kare=sayi_ters*sayi_ters;




    gecici=ters_kare;




    while(ters_kare!=0)
    {
        ters_kare=ters_kare/10;
        a+=1;
    }
    ters_kare=gecici;




    for(j=1;ters_kare!=0;j++)
    {
        gecici1+=(pow(10,a-j)*(ters_kare%10));
        ters_kare=ters_kare/10;

    }

    ters_kare=gecici;
    a=0;

    if (gecici1==sayi_kare)
    {
        if(i==sayi_ters)
            continue;
        printf("%d ender bulunan bir sayidir.\n",i);
        adet+=1;
    }
    gecici1=1;
    sayi_ters=0;
    sayi_kare=0;
    ters_kare=0;


}
printf("%d tane ender sayi vardir.\n",adet);

}







int main()
{
    ender_sayi();
    return 0;
}
