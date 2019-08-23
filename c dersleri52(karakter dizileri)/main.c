#include <stdio.h>
#include <stdlib.h>

// alistirma
/*int main()
{
    char dizi[12];
    printf("adinizi giriniz:");
    scanf("%s",dizi);
    printf("\nmerhaba %s\n",dizi);
    return 0;
}*/




//stringi ters yazdirma


/*void tersyaz(int kasa,char name[])
{
    int i;
    for(i=kasa-1;i>=0;i--)
    {
        printf("%c",name[i]);
    }
    printf("\n");
}
int main()
{
    char ad[20];
    int karaktersayisi=0;
    printf("adinizi giriniz:");
    scanf("%s",ad);
    int i;
    for(i=0;ad[i]!='\0';i++)
    {
        karaktersayisi++;
    }
    tersyaz(karaktersayisi,ad);

    return 0;
}*/


//gets puts kullanimi



/*int main()
{
    int a=10,b=20;
    char ad[8];
    printf("bir cumle yaziniz:");
    gets(ad);
    puts(ad);
    return 0;
}*/


//fgets kullanimi



/*int main()
{
    char dizi[8];
    int a=10,b=20;
        printf("a: %d ve b: %d\n\n", a, b);
    printf("programi 8 veya daha fazla karakter girerek test edin\n");
    printf("kelime girin: ");
    fgets(dizi, 8, stdin); // gets yerine bu sekilde kullanabiliriz
    // scanf ile kelime okumak istersek
     //scanf("%7s", dizi);
    printf("girilen kelime: ");
    puts(dizi);
    printf("\na: %d ve b: %d\n", a, b);
    return 0;
}*/




//stringin icinde harf arama


/*int uzun(const char *s)
{
    int i;
    i=0;
    while(s[i]!='\0')
        i++;
    return i;
}
int bul(const char *b,char c)
{
    int i;
    for(i=0;b[i]!='\0';i++)
    {
        if(b[i]==c)
            return i;
    }
    return -1;
}
int main()
{
    char dizi[50];
    char a;
    printf("birseyler yazin:\n\n");
    fgets(dizi,50,stdin);
    printf("cumlenin uzunlugu:%d",uzun(dizi));
    printf("aramak istediginiz harfi yazin:");
    scanf("%c",&a);
    int yer=bul(dizi,a);
    if (yer==-1)
        printf("aradaginiz harf cumlede yoktur.\n");
    else
        printf("aradaginiz harf %d. indistedir.\n",yer);
    return 0;
}*/



//string birlestirme


/*
int uzun(char *s)
{
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
}
void ekle(char *bas,const char *son)
{
    int i;
    int ilkdizi=uzun(bas);
    int sondizi=uzun(son);
    for (i=0;i<sondizi;i++)
    {
        bas[ilkdizi+i]=son[i];
    }
    bas[ilkdizi+sondizi]='\0';
}

int main()
{
    char first[100];
    char secound[50];
    printf("bir cimle giriniz:");
    fgets(first,50,stdin);
    printf("eklemek istediginiz:");
    fgets(secound,50,stdin);
    ekle(first,secound);
    puts(first);
    return 0;
}
*/




/*int uzun(char *s)
{
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
}
int bul(const char *al,char *ara)
{
    int i,j;
    int allong=uzun(al);
    int aralong=uzun(ara);
    for(i=0;i<=allong-aralong;i++)
    {
        for(j=0;j<aralong;j++)
        {
            if(al[i+j]!=ara[j])
                break;
        }
        if (j==aralong)
            return 1;
    }

    return -1;
}
int main()
{
    char ilk[100];
    char son[20];
    printf("bir cumle yazin:");
    fgets(ilk,100,stdin);
    printf("\ncumlenizin icinde aramak istediginiz kelime nedir:");
    fgets(son,20,stdin);
    int a=bul(ilk,son);
    if(a == -1)
        printf("\naradiginiz kelime cumlede yok!!");
    else
        printf("\naranan kelime cumlede var.");
}
*/


 /*
 int ara(const char *s)
 {
     int i,j=1;
     for(i=0;s[i]!='\0';i++)
     {
         if(s[i]==' ')
            j++;
     }
     return j;
 }
int main()
{
    char dizi[100];
    fgets(dizi,100,stdin);
    printf("%d",ara(dizi));
}

*/






