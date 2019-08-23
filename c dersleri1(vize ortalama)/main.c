#include <stdio.h>
#include <stdlib.h>
//hüseyin can kalçýk
//ders ortalama programý
int main()
{
    int vize1,vize2,final1;
    float dersort;
    float ortalama;
    printf("1.vize notunuzu giriniz:");
    scanf("%d",&vize1);
    printf("2.vize notunuzu giriniz:");
    scanf("%d",&vize2);
    printf("final notunuzu giriniz:");
    scanf("%d",&final1);
    printf("okul ortalamanýz kac:");
    scanf("%f",&ortalama);

    dersort=(vize1+vize2+final1)/3,0;

    if (dersort>65)
    {
        printf("dersten geçtiniz.\n");

    }
    else if (dersort>50)
    {
        printf("butunlemeye kaldiniz.\n");
        if (ortalama<2.5)
        {
            printf("bu dersi seneye tekrar almalisin.(tavsiyemizdir...)");
        }
    }
    else
    {
        printf("maalesef kaldiniz.\n");
    }

    return 0;
}
