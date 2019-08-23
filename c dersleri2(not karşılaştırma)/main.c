#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vize1,vize2,final1;
    float okulort;
    float dersort;
    printf("1.vize:");
    scanf("%d",&vize1);
    printf("2.vize:");
    scanf("%d",&vize2);
    printf("final1:");
    scanf("%d",&final1);
    printf("okul ortalamasi:");
    scanf("%f",&okulort);

    dersort=(vize1*3/10.0)+(vize2*3/10.0)+(final1*4/10.0);

    if (dersort>=90)
    {
        printf("harf notunuz - AA ve ders ortalamaniz:%f",dersort);

    }
    else if (dersort>=85 && dersort<90)
    {
        printf("harf notunuz - BA ve ders ortalamaniz:%f",dersort);

    }
    else if (dersort>=80 & dersort<85)
    {
        printf("harf notunuz - BB ve ders ortalamaniz:%f",dersort);

    }
    else if (dersort>=75 && dersort<80)
    {
        printf("harf notunuz - CB ve ders ortalamaniz:%f",dersort);

    }
    else if (dersort>=70 && dersort<65)
    {
        printf("harf notunuz - CC ve ders ortalamaniz:%f",dersort);

    }
    else if (dersort>=65 && dersort<70)
    {
        printf("harf notunuz - DC ve ders ortalamaniz:%f",dersort);

    }
    else if (dersort>=60 && dersort<65)
    {
        printf("harf notunuz - DD ve ders ortalamaniz:%f\n",dersort);
        printf("butunlemeye kaldiniz...");
        if (okulort<2.5)
        {
            printf("dersi bir daha almani tavsiye ediyoruz...");

        }
    }
    else
    {
        printf("harf ortalamaniz - FF ders ortalamaniz:%f\n",dersort);
        printf("maalesef kaldiniz.dersi seneye alacaksiniz. ");
    }


    return 0;
}
