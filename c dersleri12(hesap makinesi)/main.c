#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i,sec;
    float number=0;
    float sonuc=0;

while(i!=0)
{
    printf("\n1-)toplama\n2-)cikartma\n3-)carpma\n4-)bolme\n5-)cikis\n");
    printf("seciminiz:");
    scanf("%d",&sec);
if (sec==5)
{
    printf("cikiliyor...");
    break;
}
    switch (sec)
    {
    case 1:
        sonuc=0;
        printf("sonuc icin 0'a basmalisiniz.\n");
        for (i=1;i!=0;i++)
        {
            printf("%d.sayi:",i);
            scanf("%f",&number);
            if (number==0)
            {
                printf("sonuc:%.1f",sonuc);
                break;
            }
        sonuc=sonuc+number;
        }
        break;
    case 2:
        sonuc=0;
        printf("sonuc icin 0'a basmalisiniz.\n");
        for (i=1;i!=0;i++)
        {
            printf("%d.sayi:",i);
            scanf("%f",&number);
            if (number==0)
            {
                printf("sonuc:%.1f",sonuc);
                break;
            }
        sonuc=sonuc-number;
        }
        break;

    case 3:
        sonuc=0;
        printf("sonuc icin 1'e basmalisiniz.\n");
        for (i=1;i!=0;i++)
        {
            printf("%d.sayi:",i);
            scanf("%f",&number);
            if (number==1)
            {
                printf("sonuc:%.1f",sonuc);
                break;
            }
            sonuc=sonuc*number;

        }
        break;
    case 4:
        sonuc=0;
        printf("sonuc icin 1'e basmalisiniz.\n");
        for (i=1;i!=0;i++)
        {
            printf("%d.sayi:",i);
            scanf("%f",&number);
            if (number==1)
            {
                printf("sonuc:%.1f",sonuc);
                break;
            }
        sonuc=sonuc/number;
        }
        break;

    default:
        sonuc=0;
        printf("yanlis bir ifade kullandiniz.\ntekrar deneyiniz.\n");
        break;

    }

  }
    return 0;
}
