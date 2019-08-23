#include <stdio.h>
#include <stdlib.h>

int main()
{

    int paralar[3];
    char urunler[] = "10,20,10\n1,su,30,0.5\n2,cay,20,1\n3,kahve,15,1.5\n4,cikolata,50,1.75\n5,biskuvi,100,2";
    char *urunlertakip=urunler;
    char uruntemp[5][25];
    char * pch;
    char * tch;



    int urunId;
    char urunAdi[10];
    int stok;
    float urunFiyat;

    int istek=1;

while(istek!=0){

        /*enter tusuna gore yazinin ayrilmasi*/
        printf("bir sayi giriniz:");
        scanf("%d",&istek);

        tch = strtok (urunlertakip,"\n");
        for(int j=0;j<6;j++){
            sscanf(tch,"%s",uruntemp[j]);
            tch = strtok (NULL, "\n");
        }
        free(urunlertakip);
            /*enter tusuna gore yazinin ayrilmasi*/




            /*para kisminin atanmasi*/
        pch = strtok (uruntemp[0],",");
        for(int j=0;j<3;j++){

            paralar[j]=atoi(pch);
            //printf("paralar : %d\t%d\t%d\n",paralar[0],paralar[1],paralar[2]);
            pch = strtok (NULL, ",");
        }
        /*para kisminin atanmasi*/







        /*urun degerlerinin atanmasi*/
        for(int k=1;k<6;k++){
            pch = strtok (uruntemp[k],",");
            for(int j=0;j<4;j++){
                if(j==0){
                    urunId=atoi(pch);
                }
                if(j==1){
                    sscanf(pch,"%s",urunAdi);
                }
                if(j==2){
                    stok=atoi(pch);
                }
                if(j==3){
                    urunFiyat=atof(pch);
                }
                pch = strtok (NULL, ",");
            }

            //printf("urunler : %d\t%s\t%d\t%f\n",urunId,urunAdi,stok,urunFiyat);
        }
        /*urun degerlerinin atanmasi*/





        /*stringin guncellenmesi*/


        sprintf(uruntemp[0],"%d,%d,%d",paralar[0],paralar[1],paralar[2]);
        for(int j=1;j<6;j++){
            sprintf(uruntemp[j],"%d,%s,%d,%f",urunId,urunAdi,stok,urunFiyat);
            //printf("%s\n",uruntemp[j]);
        }

        urunlertakip=(char*)malloc(sizeof(char)*200);
        sprintf(urunlertakip,"%s\n%s\n%s\n%s\n%s\n%s",uruntemp[0],uruntemp[1],uruntemp[2],uruntemp[3],uruntemp[4],uruntemp[5]);
        printf("%s\n",urunlertakip);

        /*stringin guncellenmesi*/
}

    return 0;
}
