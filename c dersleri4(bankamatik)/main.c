#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bakiye=1000;
    int islem;
    int tutar;
    printf("1-)para cekme\n2-)para yat�rma\n3-)havale yapma\n4-)bakiye sorgulama\n5-)kart iade\n");
    printf("isleminiz:");
    scanf("%d",&islem);
    switch(islem)
    {


        case 1:
            printf("bakiyeniz:%d\n",bakiye);
            printf("�ekmek istediginiz tutar:");
            scanf("%d",&tutar);
            if (tutar>bakiye)
            {
                printf("bakiye yetersiz.");
            }
            bakiye-=tutar;
            printf("bakiyeniz:%d",bakiye);
            printf("islem basar�yla gerceklestirildi.");
            break;

        case 2:
            printf("yat�r�lacak tutar:");
            scanf("%d",&tutar);
            bakiye+=tutar;
            printf("bakiyeniz:%d",bakiye);
            break;


        case 3:
            printf("bakiyeniz:%d\n",bakiye);
            printf("havale yap�lacak tutar:");
            scanf("%d",&tutar);
            if (tutar>bakiye)
            {
                printf("bakiye yetersiz.");
            }
            bakiye-=tutar;
            printf("bakiyeniz:%d\n",bakiye);
            printf("islem basar�yla gerceklestirildi.");
            break;


        case 4:
            printf("bakiyeniz:%d",bakiye);
            break;


        case 5:
            printf("kart iade ediliyor...");
            break;
       default:
       {
            printf("yanlis bir ifade girdiniz.");
       }
    }
    return 0;
}
