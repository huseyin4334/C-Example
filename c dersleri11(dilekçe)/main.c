#include <stdio.h>
#include <stdlib.h>

int main()
{
    char kime,kimden;
    int gun,ay,yil;
    printf("g�nderilenin ismi:");
    scanf("%c",&kime);
    printf("g�nderenin ismi:");
    scanf("%c",&kimden);
    printf("g�n:");
    scanf("%d",&gun);
    printf("ay:");
    scanf("%d",&ay);
    printf("y�l:");
    scanf("%d",&yil);




    printf(" Sayin %c,\n",kime);
    printf("%d.%d.%d tarihinde yapt�g�n�z ba�vurunun sonuclanmas� husunda yard�mlar�n�z� rica ederiz.\n",gun,ay,yil);
    printf("\t\tsayg�lar�m�zla   %c",kimden);

        return 0;
}
