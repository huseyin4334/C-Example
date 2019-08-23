#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*---------------------------------odev 1-----------------------------------*/

int stringkontrol(char kelime[]){
    int karaktersayisi = 0;
    int harf=0;
    int rakam=0;
    for(int i=0;kelime[i]!='\0';i++){
        if(kelime[i]>=48 && kelime[i]<=57){
            if(i==0){
                printf("rakamla baslayamazsiniz");
                return 0;
            }
            karaktersayisi++;
            rakam++;
        }

        else if((kelime[i]>=65 && kelime[i]<=90) || (kelime[i]>=97 && kelime[i]<=122)){
            if(kelime[i+1]=='\0'){
                printf("harf ile bitiremezsiniz");
                return 0;
            }
            harf++;
            karaktersayisi++;
        }
        else{
            printf("gecersiz karakter");
            return 0;
        }

    }
    if(karaktersayisi > 8 || karaktersayisi < 8){
        printf("Karakter sayisi 8 olmalidir.\n");
        return 0;
    }
    else if(harf == 0){
        printf("En az bir harf olmalidir.\n");
        return 0;
    }
    else if(rakam == 0){
        printf("En az bir rakam olmalidir.\n");
        return 0;
    }



    return 1;
}

/*---------------------------------odev 1-----------------------------------*/

/*---------------------------------odev 2-----------------------------------*/
void pwm(int periyod,int dolulukorani){
    int cizgi = (periyod - 1) * 3;
    int ilerle = ((cizgi * dolulukorani) / 100)+2;
    printf("1|");
    for(int i=0; i<ilerle ; i++){
        printf("-");
    }
    printf("\n");
    for(int i=0; i<10 ; i++){
        printf(" |\n");
    }
    printf("0|");
    for(int i=0; i<ilerle ; i++){
        printf(" ");
    }
    for(int i=0; i<cizgi-ilerle ; i++){
        printf("-");
    }
    printf("\n  ");
    for(int i=1; i<9 ; i++){
        printf("%d  ",i);
    }
    for(int i=9; i<=periyod ; i++){
        printf("%d ",i);
    }
}

/*---------------------------------odev 2-----------------------------------*/








int main()
{

    /*---------------------------------odev 1-----------------------------------*/
    /*char kelime[15];
    while(1){
        printf("Kurallara uygun bir kelime giriniz : ");
        scanf("%s",kelime);
        int donum = stringkontrol(kelime);
        printf("Geri donulen deger : %d\n",donum);
        if(kelime[0]=='0')
        break;
    }*/
    /*---------------------------------odev 1-----------------------------------*/





    /*---------------------------------odev 2-----------------------------------*/
    //pwm(40,75);
    /*---------------------------------odev 2-----------------------------------*/






    /*---------------------------------odev 3-----------------------------------*/

    /*float d1[] = {1.0, 2.0, 3.0, 4.0};
    float d2[] = {1.5, 2.1, 3.1, 4.1};

    FILE *deneme1;

    if ((deneme1 = fopen("file2.txt", "w")) == NULL) {
        printf("dosya acilamadi!\n");
        exit(1);
    }
    for(int i = 0 ; i<4 ; i++){
        fprintf(deneme1,"%d %f %f\n",i,d1[i],d2[i]);
    }
    fclose(deneme1);



    if ((deneme1 = fopen("file2.txt", "r")) == NULL) {
        printf("dosya acilamadi!\n");
        exit(1);
    }

    int j;
    float elemanlar[3];
    double RMSE = 0.0;
    char buf[100];
    char * pch;
    int sayac = 0;


    while ( fgets(buf, 100, deneme1) != NULL ) {

        pch = strtok (buf," ");
        // parcalama icin kullanilan ayýrýcýlar (delimiters)

        while (pch != NULL)
        {
            elemanlar[sayac]=atof(pch);
            pch = strtok (NULL, " ");
            sayac++;
        }
        RMSE = RMSE + pow((elemanlar[1]-elemanlar[2]),2);
        sayac=0;

    }

    fclose(deneme1);
    RMSE = sqrt(RMSE/4);
    printf("%f ",RMSE);

    FILE *deneme3;
    deneme3=fopen("file2.txt","a");
    if(RMSE<0.1)
        fprintf(deneme3,"%s %f - %s","RMSE",RMSE,"esdeger veriler.");

    else
        fprintf(deneme3,"%s %f - %s","RMSE",RMSE,"esdeger olmayan veriler.");*/
    /*---------------------------------odev 3-----------------------------------*/


    return 0;
}
