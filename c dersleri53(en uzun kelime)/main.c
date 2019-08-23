#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bul(char *s)
{
    int i,j;
    int b;
    int sayac=0;
    int enbuyuk=0;
    printf("%d\n",strlen(s));
    for (i=0;s[i]!='\0';i++)
    {
        for(j=i;s[j]!=' ' && s[j]!='\0';j++)
        {
            sayac++;
            printf("%d   %d  %d\n",b,sayac,enbuyuk);
        }
        if(sayac>enbuyuk)
        {
            b=i;
            enbuyuk=sayac;
        }
        sayac=0;
        if(s[j]!='\0')
            i=j;
        else
            i=j-1;
    }
    printf("cumledeki en uzun kelime:");
    for(i=b;i<b+enbuyuk;i++)
    {
        printf("%c",s[i]);
    }
}
void bul1(char *s)
{
    int i;
    int b;
    int sayac=0;
    int enbuyuk=0;
    printf("%d\n",strlen(s));
    for (i=0;i<strlen(s);i++)
    {

        if(s[i]==' ' || s[i]=='\0')
        {
            if(sayac>enbuyuk)
            {
                b=i-sayac;
                enbuyuk=sayac;
            }
            sayac=0;
            continue;
        }
        sayac++;
        printf("%d   %d   %d   \n",sayac,enbuyuk,b);
    }

printf("cumledeki en uzun kelime:");
    for(i=b;i<b+enbuyuk;i++)
    {
        printf("%c",s[i]);
    }
}
int main()
{
    char dizi[100];
    printf("cumlenizi girin:");
    fgets(dizi,100,stdin);
    bul1(dizi);

    return 0;
}
