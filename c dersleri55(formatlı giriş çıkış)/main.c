#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    /*int a = 50;
    	float b = 99.9558;
    	char c[] = "deneme";
    		printf("%10d\n", a);
    			printf("%10f\n", b);
    				printf("%10s\n", c);*/


    				/*int a = 50;
                    int b = 150;
                    printf("%06d\n", a);
                    printf("%06d\n", b);*/



                    /*float b = 99.9558;
                    printf("%.4f\n", b);
                    printf("%.2f\n", b);
                    printf("%10.3f\n", b);*/




                   /* char c[] = "deneme";
	printf("0:%s:\n", c); // Normal
	printf("1:%10s:\n", c); // 10 karakterlik alan saga dayali
    printf("2:%.3s:\n", c); // ilk 3 karakter
    printf("3:%-10s:\n", c); // 10 karakterlik alan sola dayali
    printf("4:%10.3s:\n", c); // 10 karakterlik alan ilk 3 karakter
    printf("5:%.3s:\n", c+2); // [2,5] arasi karakteri yazdir*/



    /*int a=50;
    float b=76.4324242;
    char s1[30];
    sprintf(s1,"sprintf ornek %d , %.2f",a,b);
    printf("%s\n",s1);
    printf("%s\n",s1);*/



    /*char s2[] = "aaa 10 7.5";
    printf("s2: %s\n", s2);
    char x[20];
	int y;
    float z;

    sscanf(s2, "%s %d %f", x, &y, &z);
    printf("x: %s\n", x);
    printf("y: %d\n", y);
    printf("z: %f\n", z);*/




/*
    char basharf;
    char ad[10];
    char soyad[10];
    char adsoyad[20];
    printf("ad soyad:");
    fgets(adsoyad,19,stdin);
while(getchar()!='\n');
printf("ad:");
    scanf("%9s",ad);
while(getchar()!='\n');
printf("soyad:");
    scanf("%9s",soyad);
while(getchar()!='\n');
printf("adinizin bas harfi:");
    scanf("%c",&basharf);
    printf("\n\n");
    printf("Adýnýz Soyadýnýz : !%s!\n", adsoyad);
    printf("Adýnýz : !%s!\n", ad);
    printf("Soyadýnýz : !%s!\n", soyad);
    printf("Ýsminizin Baþ Harfi : !%c!\n", basharf);*/


    /*int i;

    for (i=32;i<64;i++)
    {
        printf("|%-2c %3d|%-2c  %3d|%-2c  %3d|\n",i,i,i+32,i+32,i+64,i+64);

    }*/




    char dizi[5][15]={"hus32ey5in","ali2ri2z8a","23murat","1a4hme5t"};
    char c[12];
    int i,j;

    for(i=0;i<5;i++)
    {
        for(j=0;j<15;j++)
        {
            printf("%c",dizi[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<15;j++)
        {
            if(isdigit(dizi[i][j]))
                printf("%c",dizi[i][j]);
        }
        printf("\n");
    }








    return 0;
}
