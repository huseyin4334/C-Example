#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
 	//float b = 99.9558;
    // virgulden sonraki basamak sayisi
    /*printf("%.4f\n", b);
    printf("%.2f\n", b);
    printf("%10.3f\n", b);
    	char c[] = "deneme";
	printf("0:%s:\n", c); // Normal
	printf("1:%10s:\n", c); // 10 karakterlik alan saga dayali
    printf("2:%.3s:\n", c); // ilk 3 karakter*/

    //int a = 50;
    /************ stringe yazdirma ****************/
    /*char s1[30];
    sprintf(s1, "sprintf ornek. %d %.2f", a, b);
    printf("%s\n", s1);
    printf("%s\n", s1);
    printf("%s\n", s1);
    int x;
    float y;
    char z[20];
    sscanf(s1,"%s %d %f",z,x,y);
    printf("x: %s\n", z);
    printf("y: %d\n", x);
    printf("z: %f\n", y);


        int i;
        for (i = 'A' ; i <= 'Z' ; i++) {
            printf("|%-3c %3d|%-3c %3d|\n", i,i, i+32, i+32);



            	char s[100];
                // gets fonksiyonu ile cumle okunabilir (bosluklar dahil).
                // scanf %s ile kelime okunabiliyor. scanf %s bosluklari almiyor.
                printf("cumle girin: ");
                gets(s);
                printf("cumle: ");
                puts(s);*/


         /*char c='a';
         c++;
         printf("%c %c %c",c+1,c+2,c+3);*/



         char b[5]="100";
         int j,i;
         int sayi=0;
         double a;
         j=0;
         for(i=strlen(b)-1;i>=0;i--)
         {
             //printf("%d",strlen(b));
             a=pow(10,i);
             sayi=sayi+(a*(b[j]-48));
             j++;
         }
         printf("%d",sayi);


    return 0;
}
