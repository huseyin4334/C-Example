#include <stdio.h>
#include <stdlib.h>


int **matrisolustur(int harita,int *anayol);
int *anayolyonu(int anayolyon[4]);
int **yogunlukbul(int harita,int **sayimatrisi);
int yogunluklar[9];
int main()
{

    int i,j;
    int *anayolyon;
    int oldumu;
    int **matris;
    int **yogunlukile;
    int anayollar[4];
    do{
            oldumu=0;
        printf("Harita seciminiz : ");
        scanf("%d",&i);
        if(i!=1 || i!=2)
        {
            oldumu=1;
        }
    }while(oldumu==1);


    printf("LUTFEN YOL BILGISINI GIRINIZ\n");
    if(i == 1){

        anayolyon = anayolyonu(anayollar);
        matris=matrisolustur(1,anayolyon);
                    for(i=0;i<4;i++)
                    {
                        for(j=0;j<9;j++)
                        {
                            printf("%3d",matris[i][j]);
                        }
                        printf("\n");
                    }
        yogunlukile=yogunlukbul(1,matris);
                    for(i=0;i<4;i++)
                    {
                        for(j=0;j<9;j++)
                        {
                            printf("%3d",yogunlukile[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    for(i=0;i<8;i++)
                    {
                        printf("%d ",yogunluklar[i]);
                    }
    }
/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
    else if(i==2)
    {
        anayolyon = anayolyonu(anayollar);
        matris = matrisolustur(2,anayolyon);
                    for(i=0;i<4;i++)
                    {
                        for(j=0;j<10;j++)
                        {
                            printf("%3d",matris[i][j]);
                        }
                        printf("\n");
                    }
        yogunlukile=yogunlukbul(2,matris);
                    for(i=0;i<4;i++)
                    {
                        for(j=0;j<10;j++)
                        {
                            printf("%3d",yogunlukile[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    for(i=0;i<9;i++)
                    {
                        printf("%d",yogunluklar[i]);
                    }
    }
    else{
        printf("yanlis karakter bir daha deneyiniz...\n");
    }

    return 0;
}





int *anayolyonu(int anayolyon[4])
{
    int i,k,l,oldumu=0;
    int yolyonu;
    char anayol[4]={'x','y','z','t'};
            printf("giris yolu icin 1'e, cikis yolu icin 2'ye basin.\n");
        do//bu olayin en az 1 kez gerçeklesmesi gerek.
        {

            k=0;l=0;oldumu=0;//eger dongude 2 giris 2 cıkıs alamazsak basa doner.bu degerleri sıfırlamamız gerek.
            for(i=0;i<4;i++)
            {
                git:
                printf("%c yolu : ",anayol[i]);
                scanf("%d",&yolyonu);
                anayolyon[i]=1;
                if(yolyonu==1 && k<2)
                {
                    k++;
                }
                else if(yolyonu==2 && l<2)
                {
                    anayolyon[i]=anayolyon[i]*-1;
                    l++;
                }
                else if(yolyonu!=1 || yolyonu!=2)
                {
                    printf("bu degeri giremezsiniz.");
                    goto git;
                }
                else
                {
                    oldumu=1;
                }
            }
            if(oldumu==1){
                printf("2 giris ve 2 cikis olmak zorunda.\n");
            }
        }while(oldumu!=0);
        printf("bir sonraki asamaya gecebiliriz.\n\n\n");

        return anayolyon;
}


int **matrisolustur(int harita,int *anayol)
{
    int i,j;
    char bas,son;
    int girisicikis[4];
    char arayolad[5]={'B','D','C','A','E'};
    char anayolad[4]={'x','y','z','t'};

    int **matris=(int**)malloc(4*sizeof(int*));//olusturalacak matrisi tanýimlama


    if(harita==1)//arita 1 icin yapilacak islemler
    {
        for(i=0;i<4;i++)//olusturulan matris icin sutun olusturma
        {
            matris[i]=(int*)malloc(9*sizeof(int));
            girisicikis[i]=anayol[i];
            for(j=0;j<9;j++)
            {
                    matris[i][j]=0;
            }
        }


        for(i=0;i<4;i++)//her yol icin dongu doner
        {
            basadon:
            fflush(stdin);
            printf("\n%c yolu icin ;\n",arayolad[i]);
            printf("baslangic noktasi : ");
            scanf("%c",&bas);
            while('\n'!=getchar());
            printf("yonu : ");
            scanf("%c",&son);
            matris[i][i]=anayol[i];

            //baslangýc ve yon alindi

            if(bas==anayolad[i])//baslangýc noktasi kontrolu yapiliyor sonra bunun uzerinden degerler verilecek
            {
                matris[i][i+4]=-1;
                girisicikis[i]--;
                if(girisicikis[i]<-2)
                {
                    girisicikis[i]++;
                    printf("bu yol icin bu yonu veremezsiniz.\n");
                    goto basadon;
                }
                if(i==3)
                {
                    matris[0][i+4]=1;
                    girisicikis[0]++;
                    if(girisicikis[0]>2)
                    {
                        girisicikis[0]--;
                        printf("bu yol icin bu yonu veremezsiniz.\n");
                        goto basadon;
                    }
                }
                else if(i!=3)
                {
                    matris[i+1][i+4]=1;
                    girisicikis[i+1]++;
                        if(girisicikis[i+1]>2)
                        {
                            girisicikis[i+1]--;
                            printf("bu yol icin bu yonu veremezsiniz.\n");
                            goto basadon;
                        }
                }


            }

/*---------------------------------------------------------------*/

            else//baslangýc noktasý tam tersiyse yapilacaklar
            {
                matris[i][i+4]=1;
                girisicikis[i]++;
                    if(girisicikis[i]>2)
                    {
                        girisicikis[i]--;
                        printf("bu yol icin bu yonu veremezsiniz.\n");
                        goto basadon;
                    }
                    printf("%d c",girisicikis[i]);
                if(i==3)
                {
                    matris[0][i+4]=-1;
                    girisicikis[0]--;
                    if(girisicikis[0]<-2)
                    {
                        printf("bu yol icin bu yonu veremezsiniz.\n");
                        girisicikis[0]++;
                        goto basadon;
                    }
                }

                else if(i!=3)
                {
                    matris[i+1][i+4]=-1;
                    girisicikis[i+1]--;
                    if(girisicikis[i+1]<-2)
                    {
                        printf("bu yol icin bu yonu veremezsiniz.\n");
                        girisicikis[i+1]++;
                        goto basadon;
                    }
                }
            }
        }

        printf("\nevet...diger asamaya geciyoruz.\n\n");

        printf("\n\n\n");
    }
        /*--------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------------*/



    else if(harita == 2)
    {
        for(i=0;i<4;i++)
        {
            matris[i]=(int*)malloc(10*sizeof(int));
            for(j=0;j<10;j++)
            {
                    matris[i][j]=0;

            }
            matris[i][i]=anayol[i];
        }


        for(i=0;i<5;i++)
        {
            basadoner:
            fflush(stdin);
            printf("\n%c yolu icin ;\n",arayolad[i]);
            printf("baslangic noktasi : ");
            scanf("%c",&bas);
            while('\n'!=getchar());
            printf("yonu : ");
            scanf("%c",&son);


        if(i!=4)
        {
            if(bas==anayolad[i])//baslangýc noktasi kontrolu yapiliyor sonra bunun uzerinden degerler verilecek
            {
                matris[i][i+4]=-1;
                girisicikis[i]--;
                if(girisicikis[i]<-2)
                {
                    girisicikis[i]++;
                    printf("bu yol icin bu yonu veremezsiniz.\n");
                    goto basadoner;
                }
                if(i==3)
                {
                    matris[0][i+4]=1;
                    girisicikis[0]++;
                    if(girisicikis[0]>2)
                    {
                        girisicikis[0]--;
                        printf("bu yol icin bu yonu veremezsiniz.\n");
                        goto basadoner;
                    }
                }
                else if(i!=3)
                {
                    matris[i+1][i+4]=1;
                    girisicikis[i+1]++;
                        if(girisicikis[i+1]>2)
                        {
                            girisicikis[i+1]--;
                            printf("bu yol icin bu yonu veremezsiniz.\n");
                            goto basadoner;
                        }
                }


            }
/*---------------------------------------------------------------*/

            else//baslangýc noktasý tam tersiyse yapilacaklar
            {
                matris[i][i+4]=1;
                girisicikis[i]++;
                    if(girisicikis[i]>2)
                    {
                        girisicikis[i]--;
                        printf("bu yol icin bu yonu veremezsiniz.\n");
                        goto basadoner;
                    }
                    printf("%d c",girisicikis[i]);
                if(i==3)
                {
                    matris[0][i+4]=-1;
                    girisicikis[0]--;
                    if(girisicikis[0]<-2)
                    {
                        printf("bu yol icin bu yonu veremezsiniz.\n");
                        girisicikis[0]++;
                        goto basadoner;
                    }
                }

                else if(i!=3)
                {
                    matris[i+1][i+4]=-1;
                    girisicikis[i+1]--;
                    if(girisicikis[i+1]<-2)
                    {
                        printf("bu yol icin bu yonu veremezsiniz.\n");
                        girisicikis[i+1]++;
                        goto basadoner;
                    }
                }
            }
        }
        else
        {
            if(bas=='t')
            {
                if(anayol[3]==1){
                    printf("bu yol icin bu yonu veremezsiniz.");
                    goto basadoner;
                }
                else
                {
                    matris[1][8]=1;
                    matris[3][8]=-1;
                }

            }
            else
            {
                if(anayol[1]==1){
                    printf("bu yol icin bu yonu veremezsiniz.");
                    goto basadoner;
                }
                else
                {
                    matris[1][8]=-1;
                    matris[3][8]=1;
                }
            }

        }
        }
        printf("\nevet...diger asamaya geciyoruz.\n\n");
    }


    return matris;
}



int **yogunlukbul(int harita,int **sayimatrisi)
{
    int i,j,k=4;
    int yogunluk,oldumu=0;
    int **matris=(int**)malloc(4*sizeof(int*));
    int bilinmeyenkontrol=0;
    char arayolad[5]={'B','D','C','A','E'};
    char anayolad[4]={'x','y','z','t'};
    //int yogunluklar[10];

    if(harita==1)
    {

        for(i=0;i<4;i++)
        {
            matris[i]=(int*)malloc(9*sizeof(int));
            for(j=0;j<9;j++)
            {
                    matris[i][j]=sayimatrisi[i][j];
            }
        }
        printf("yollarin yogunluk degerlerini giriniz.\ndeger vermek istemiyorsaniz -1'e basin.\n");
        donus:
        printf("en az 1 yol bilinmeyen olmak zorundadir.\n");
        for(i=0;i<4;i++)
        {

            do
            {
                oldumu=0;
                printf("\n%c yolu yol yogunlugu : ",anayolad[i]);
                scanf("%d",&yogunluk);

                if(yogunluk>=0)
                    {
                        yogunluklar[i]=yogunluk;
                        if(sayimatrisi[i][i]==1)
                        {
                            matris[i][8]=matris[i][8]-yogunluk;
                        }
                        else
                        {
                            matris[i][8]=matris[i][8]+yogunluk;
                        }
                        matris[i][i]=0;
                    }
                    else if(yogunluk<-1)
                    {
                        printf("bu degeri veremezsiniz");
                        oldumu=1;
                    }
                    else
                    {
                        bilinmeyenkontrol++;
                        yogunluklar[i]=yogunluk;
                    }

            }while(oldumu==1);

        }

        for(i=0;i<4;i++)
        {
            do
            {
                oldumu=0;
                printf("\n%c yolu yol yogunlugu : ",arayolad[i]);
                scanf("%d",&yogunluk);
                if(yogunluk>=0)
                    {
                        yogunluklar[i+4]=yogunluk;
                        if(sayimatrisi[i][k]==1)
                        {
                            matris[i][k]=0;
                            matris[i][8]=matris[i][8]-yogunluk;
                            if(k==7)
                            {
                                matris[0][8]=matris[0][8]+yogunluk;
                                matris[0][k]=0;
                            }
                            else
                            {
                                matris[i+1][8]=matris[i+1][8]+yogunluk;
                                matris[i+1][k]=0;
                            }
                            k++;
                        }
                        else
                        {
                            matris[i][k]=0;
                            matris[i][8]=matris[i][8]+yogunluk;
                            if(k==7)
                            {
                                matris[0][8]=matris[0][8]-yogunluk;
                                matris[0][k]=0;
                            }
                            else
                            {
                                matris[i+1][8]=matris[i+1][8]-yogunluk;
                                matris[i+1][k]=0;
                            }
                            k++;
                        }
                    }
                    else if(yogunluk<-1)
                    {
                        printf("bu degeri veremezsiniz");
                        oldumu=1;
                    }
                    else
                    {
                        yogunluklar[i+4]=yogunluk;
                        bilinmeyenkontrol++;
                        k++;
                    }

                }while(oldumu==1);

            }
            if(bilinmeyenkontrol==0)
                {
                    printf("en az bir yol bilinmeyen olmak zorunda.");
                    k=0;
                    bilinmeyenkontrol=0;
                    for(i=0;i<4;i++)
                    {
                        for(j=0;j<9;j++)
                        {
                            matris[i][j]=sayimatrisi[i][j];
                        }
                    }
                    goto donus;
                }
    }

/*---------------------------------------------------------------------------------------------------------------------------------------*/
    if(harita==2)
    {
        k=0;
        for(i=0;i<4;i++)
        {
            matris[i]=(int*)malloc(10*sizeof(int));
            for(j=0;j<9;j++)
            {
                    matris[i][j]=sayimatrisi[i][j];
            }
        }
        printf("yollarin yogunluk degerlerini giriniz.\ndeger vermek istemiyorsaniz -1'e basin.\n");
        donus1:
        printf("en az 1 yol bilinmeyen olmak zorundadir.\n");
        for(i=0;i<4;i++)
        {

            do
            {
                oldumu=0;
                printf("\n%c yolu yol yogunlugu : ",anayolad[i]);
                scanf("%d",&yogunluk);
                if(yogunluk>=0)
                    {
                        yogunluklar[i]=yogunluk;
                        if(sayimatrisi[i][i]==1)
                        {
                            matris[i][9]=matris[i][9]-yogunluk;
                        }
                        else
                        {
                            matris[i][9]=matris[i][9]+yogunluk;
                        }
                        matris[i][i]=0;
                    }
                    else if(yogunluk<-1)
                    {
                        printf("bu degeri veremezsiniz");
                        oldumu=1;
                    }
                    else
                    {
                        yogunluklar[i]=yogunluk;
                        bilinmeyenkontrol++;
                    }

            }while(oldumu==1);

        }

        for(i=0;i<5;i++)
        {
            if(i!=5)
            {
                do
                {
                oldumu=0;
                printf("\n%c yolu yol yogunlugu : ",arayolad[i]);
                scanf("%d",&yogunluk);
                if(yogunluk>=0)
                    {
                        yogunluklar[i+4]=yogunluk;
                        if(sayimatrisi[i][k]==1)
                        {
                            matris[i][k]=0;
                            matris[k][9]=matris[i][9]-yogunluk;
                            if(k==7)
                            {
                                matris[0][9]=matris[0][9]+yogunluk;
                                matris[0][k]=0;
                            }
                            else
                            {
                                matris[i+1][9]=matris[i+1][9]+yogunluk;
                                matris[i+1][k]=0;
                            }
                            k++;
                        }
                        else
                        {
                            matris[i][k]=0;
                            matris[i][9]=matris[i][9]+yogunluk;
                            if(k==7)
                            {
                                matris[0][9]=matris[0][9]-yogunluk;
                                matris[0][k]=0;
                            }
                            else
                            {
                                matris[i+1][9]=matris[i+1][9]-yogunluk;
                                matris[i+1][k]=0;
                            }
                            k++;
                        }
                    }
                    else if(yogunluk<-1)
                    {
                        printf("bu degeri veremezsiniz.\n");
                        oldumu=1;
                    }
                    else
                    {
                        yogunluklar[i+4]=yogunluk;
                        bilinmeyenkontrol++;
                        k++;
                    }

                }while(oldumu==1);

            }
                else if(i==5)
                {
                    do
                    {
                        oldumu=0;
                        printf("\n%c yolu yol yogunlugu : ",arayolad[i]);
                        scanf("%d",&yogunluk);
                        if(yogunluk>=0)
                        {
                            yogunluklar[9]=yogunluk;
                            if(sayimatrisi[1][8]==1)
                            {
                                matris[1][9]=matris[1][9]-yogunluk;
                                matris[1][8]=0;
                                matris[3][9]=matris[3][9]+yogunluk;
                                matris[3][8]=0;
                            }
                            else
                            {
                                matris[1][9]=matris[1][9]+yogunluk;
                                matris[1][8]=0;
                                matris[3][9]=matris[3][9]-yogunluk;
                                matris[3][8]=0;
                            }
                        }
                        else if(yogunluk<-1)
                        {
                                printf("bu degeri veremezsiniz.\n");
                                oldumu=1;
                        }
                        else
                        {
                            yogunluklar[8]=yogunluk;
                            k++;
                            bilinmeyenkontrol++;
                        }
                    }while(oldumu==1);

                }
            }
                if(bilinmeyenkontrol==0)
                {
                    printf("en az bir yol bilinmeyen olmak zorunda.");
                    k=0;
                    bilinmeyenkontrol=0;
                    for(i=0;i<4;i++)
                    {
                        for(j=0;j<10;j++)
                        {
                            matris[i][j]=sayimatrisi[i][j];
                        }
                    }
                    goto donus1;
                }
    }
    return matris;
}
















