#include <stdio.h>
#include <stdlib.h>
void iyi_sayi()
{
int i,j,k=0;
int adet=0,a=0;
int gecici;
int degisken=0;
int sayilar[50];
for (i=800;i!=0;i--)
{
    for(j=1;j<=3;j++)
    {
        gecici=i*j;
        while(gecici!=0)
            {
                sayilar[a]=gecici%10;
                gecici=gecici/10;
                a+=1;
            }

    }
    for (j=0;j<=a;j++)
    {
        for (k=0;k<=a;k++){
            if (j!=k)
            {
                if (sayilar[j]==sayilar[k])
                {
                  degisken=1;
                }
                else
                    degisken=0;

            }
        }
    }
    if(degisken==0)
        adet+=1;
    degisken=0;
    a=0;

}
printf("%d",adet);
}



int main()
{
iyi_sayi();



    return 0;
}
