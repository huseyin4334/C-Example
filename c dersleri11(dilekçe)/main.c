#include <stdio.h>
#include <stdlib.h>

int main()
{
    char kime,kimden;
    int gun,ay,yil;
    printf("gönderilenin ismi:");
    scanf("%c",&kime);
    printf("gönderenin ismi:");
    scanf("%c",&kimden);
    printf("gün:");
    scanf("%d",&gun);
    printf("ay:");
    scanf("%d",&ay);
    printf("yýl:");
    scanf("%d",&yil);




    printf(" Sayin %c,\n",kime);
    printf("%d.%d.%d tarihinde yaptýgýnýz baþvurunun sonuclanmasý husunda yardýmlarýnýzý rica ederiz.\n",gun,ay,yil);
    printf("\t\tsaygýlarýmýzla   %c",kimden);

        return 0;
}
