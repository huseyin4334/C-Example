#include <stdio.h>
#include <stdlib.h>

int main()
{
    int kose1,kose2,kose3,kose4;
    int islem;
    printf("1-)ucgen\n2-)dortgen\n3-)cikis\nseciminiz:");
    scanf("%d",&islem);

while (islem!=3)
{



    switch (islem)
    {

        case 1:
            printf("1.kose:");
            scanf("%d",&kose1);
            printf("2.kose:");
            scanf("%d",&kose2);
            printf("3.kose:");
            scanf("%d",&kose3);


            if ((kose1+kose2)>kose3 && (kose3+kose2)>kose1 && (kose1+kose3)>kose2)
            {
                printf("verdiginiz sayilar bir ucgen olusturuyor.\ndevam edelim....");

                if ((kose1==kose2) && (kose1==kose3) && (kose3==kose2))
                {
                    printf("bu bir eskenar ucgendir.");
                }
                else if ((kose1==kose2) || (kose1==kose3) || (kose3==kose2) )
                {
                    printf("bu bir ikiz kenar ucgendir.");
                }
                else
                {
                    printf("herhangi bir ucgendir.");
                }
            }
            else
            {
                printf("bu bir ucgen degildir.");
            }

            break;
        case 2:
            printf("1.kose:");
            scanf("%d",&kose1);
            printf("2.kose:");
            scanf("%d",&kose2);
            printf("3.kose:");
            scanf("%d",&kose3);
            printf("4.kose:");
            scanf("%d",&kose4);
            if ((kose1==kose2) && (kose1==kose3) && (kose1==kose4))
            {
                printf("bu bir karedir.");
            }
            else if (((kose1==kose2) && (kose4==kose3)) || ((kose1==kose3) && (kose4==kose2)) || ((kose1==kose4) && (kose2==kose3)))
            {
                printf("bu bir ikiz kenar dortgendir.");
            }
            else
            {
                printf("herhangi bir dortgendir.");

            }
            break;
        case 3:
            printf("cıkılıyor...");
        default:
            printf("yanlis ifade...");
            break;
    }

}
    return 0;
}
