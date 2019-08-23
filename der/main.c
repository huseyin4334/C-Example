#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include<allegro5/allegro_image.h>


int **matrisolustur(int harita,int *anayol);
int *anayolyonu(int anayolyon[4]);
int **yogunlukbul(int harita,int **sayimatrisi);
void gaussjordan(int satir,int sutun,int **matris);
int yogunluklar[9];
int main() {

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP  *harita1 = NULL;
    ALLEGRO_BITMAP  *harita2 = NULL;
    ALLEGRO_BITMAP *asagiok = NULL;
    ALLEGRO_BITMAP *yukariok = NULL;
    ALLEGRO_BITMAP *sagok = NULL;
    ALLEGRO_BITMAP *solok = NULL;
    ALLEGRO_BITMAP *xy = NULL;
    ALLEGRO_BITMAP *yx = NULL;
    ALLEGRO_BITMAP *yz = NULL;
    ALLEGRO_BITMAP *zy = NULL;
    //tanimlanan degerler
    int i,j;
    int *anayolyon;
    int oldumu=0;
    int **matris;
    int **yogunlukile;
    int anayollar[4];
    //tanimlanan degerler

    //alegroyu alıstırırken hata alırsak yapılacaklar.
    if(!al_init()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!",NULL);
        return 0;
    }

    if(!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",NULL);
        return 0;
    }

    display = al_create_display(1200,600);

    if(!display) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",NULL);
        return 0;
    }
    //alegroyu alıstırırken hata alırsak yapılacaklar.

    //basilacak resimlerin tanimlanmasi
    harita1 = al_load_bitmap("resim1.png");
    harita2= al_load_bitmap("resim2.png");
    asagiok= al_load_bitmap("asagiok.png");
    yukariok= al_load_bitmap("yukariok.png");
    sagok= al_load_bitmap("sagok.png");
    solok= al_load_bitmap("solok.png");
    xy= al_load_bitmap("xy.png");
    yx= al_load_bitmap("yx.png");
    yz= al_load_bitmap("yz.png");
    zy= al_load_bitmap("zy.png");
    //basilacak resimlerin tanimlanmasi

    if(!harita1 || !harita2) {
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!",NULL);
        al_destroy_display(display);
        return 0;
    }

    al_draw_bitmap(harita1,0,0,0);
    al_draw_bitmap(harita2,625,0,0);
    al_flip_display();
    do{
        oldumu=0;
        printf("Harita seciminiz : ");
        scanf("%d",&i);

        if(i!=1 && i!=2)
        {
            oldumu=1;
            printf("BOYLE BIR HARITA YOK.\nTEKRAR DENEYINIZ.\n");
        }
    }while(oldumu==1);
    al_clear_to_color ( al_map_rgb ( 0 , 0 , 0 ));//ekrani temizle
    printf("LUTFEN YOL BILGISINI GIRINIZ\n");

    /*----------------harita 1-----------------------------------------------------------*/

    if(i == 1){

        al_draw_bitmap(harita1,300,0,0);//harita1'i yeniden bastir.
        al_flip_display();//degisiklikleri ekrana uygular.
        anayolyon = anayolyonu(anayollar);//anayolun yonlerini alma fonksiyonu

        /*bu dongude fonkdan gelen degerlere gore yon oklarini bastirir*/
        for(i=0;i<4;i++)
        {   /*her eleman acin ayri sorgu*/
            if(i==0){
                if(anayolyon[i]==1)//saat yonunun tersi icin
                    al_draw_bitmap(asagiok,565,40,0);
                else//saat yonu icin
                    al_draw_bitmap(yukariok,565,40,0);
                al_flip_display();
            }
            else if(i==1)
            {
                if(anayolyon[i]==1)//saat yonunun tersi icin
                    al_draw_bitmap(solok,800,265,0);
                else//saat yonu icin
                    al_draw_bitmap(sagok,800,265,0);
                al_flip_display();
            }
            else if(i==2)
            {
                if(anayolyon[i]==1)
                    al_draw_bitmap(yukariok,565,500,0);
                else
                    al_draw_bitmap(asagiok,565,500,0);
                al_flip_display();
            }
            else if(i==3)
            {
                if(anayolyon[i]==1)
                    al_draw_bitmap(sagok,330,265,0);
                else
                    al_draw_bitmap(solok,330,265,0);
                al_flip_display();
            }
        }
        /*--------matrisi olusturma--------------------------------------------------*/
        matris=matrisolustur(1,anayolyon);//arayollarinda olusturulmasi icin kullanilan fonksiyon
        /*arayollardan gelen degerlere gore yon oklari basilir*/
        for(i=0;i<4;i++)
        {
            /*her eleman acin ayri sorgu*/
            if(i+4==4){
                if(matris[i][i+4]==1)//saat yonunun tersi icin
                    al_draw_bitmap(yx,670,170,0);
                else//saat yonu icin
                    al_draw_bitmap(xy,670,170,0);
                al_flip_display();
            }
            else if(i+4==5)
            {
                if(matris[i][i+4]==1)
                    al_draw_bitmap(zy,650,380,0);
                else
                    al_draw_bitmap(yz,650,380,0);
                al_flip_display();
            }
            else if(i+4==6)
            {
                if(matris[i][i+4]==1)
                    al_draw_bitmap(xy,480,400,0);
                else
                    al_draw_bitmap(yx,480,400,0);
                al_flip_display();
            }
            else if(i+4==7)
            {
                if(matris[i][i+4]==1)
                    al_draw_bitmap(yz,450,170,0);
                else
                    al_draw_bitmap(zy,450,170,0);
                al_flip_display();
            }
        }
        /*-------------------------matrisi dondur---------------------------*/
        for(i=0;i<4;i++)
        {
            for(j=0;j<9;j++)
            {
                printf("%3d",matris[i][j]);
            }
            printf("\n");
        }
        /*-------------------------yogunluk degerlerini al--------------------------------------*/

        yogunlukile=yogunlukbul(1,matris);/*kullaniciden yollarin yogunluk degerlerini almak icin kullanilan fonksiyon*/

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
        gaussjordan(4,9,yogunlukile);
    }


    else if(i==2)
    {
        al_draw_bitmap(harita2,300,0,0);//harita1'i yeniden bastir.
        al_flip_display();//degisiklikleri ekrana uygular.
        anayolyon = anayolyonu(anayollar);//anayolun yonlerini alma fonksiyonu

        /*bu dongude fonkdan gelen degerlere gore yon oklarini bastirir*/
        for(i=0;i<4;i++)
        {   /*her eleman acin ayri sorgu*/
            if(i==0){
                if(anayolyon[i]==1)//saat yonunun tersi icin
                    al_draw_bitmap(asagiok,565,40,0);
                else//saat yonu icin
                    al_draw_bitmap(yukariok,565,40,0);
                al_flip_display();
            }
            else if(i==1)
            {
                if(anayolyon[i]==1)//saat yonunun tersi icin
                    al_draw_bitmap(solok,800,265,0);
                else//saat yonu icin
                    al_draw_bitmap(sagok,800,265,0);
                al_flip_display();
            }
            else if(i==2)
            {
                if(anayolyon[i]==1)
                    al_draw_bitmap(yukariok,565,500,0);
                else
                    al_draw_bitmap(asagiok,565,500,0);
                al_flip_display();
            }
            else if(i==3)
            {
                if(anayolyon[i]==1)
                    al_draw_bitmap(sagok,330,265,0);
                else
                    al_draw_bitmap(solok,330,265,0);
                al_flip_display();
            }
        }


        /*-------------------matrisi olusturma--------------------------------------------------*/


        matris=matrisolustur(2,anayolyon);//arayollarinda olusturulmasi icin kullanilan fonksiyon
        /*arayollardan gelen degerlere gore yon oklari basilir*/
        for(i=0;i<5;i++)
        {
            /*her eleman acin ayri sorgu*/
            if(i+4==4){
                if(matris[i][i+4]==1)//saat yonunun tersi icin
                    al_draw_bitmap(yx,670,170,0);
                else//saat yonu icin
                    al_draw_bitmap(xy,670,170,0);
                al_flip_display();
            }
            else if(i+4==5)
            {
                if(matris[i][i+4]==1)
                    al_draw_bitmap(zy,670,380,0);
                else
                    al_draw_bitmap(yz,670,380,0);
                al_flip_display();
            }
            else if(i+4==6)
            {
                if(matris[i][i+4]==1)
                    al_draw_bitmap(xy,470,390,0);
                else
                    al_draw_bitmap(yx,470,390,0);
                al_flip_display();
            }
            else if(i+4==7)
            {
                if(matris[i][i+4]==1)
                    al_draw_bitmap(yz,450,170,0);
                else
                    al_draw_bitmap(zy,450,170,0);
                al_flip_display();
            }
            else if(i+4==8)
            {
                if(matris[3][i+4]==1)
                    al_draw_bitmap(solok,565,265,0);
                else
                    al_draw_bitmap(sagok,565,265,0);
                al_flip_display();
            }
        }
        /*-------------------------matrisi dondur---------------------------*/

        for(i=0;i<4;i++)
        {
            for(j=0;j<10;j++)
            {
                printf("%3d",matris[i][j]);
            }
            printf("\n");
        }
        /*--------yol yogunluklarini al--------------------------------------------------*/

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
        gaussjordan(4,10,yogunlukile);
    }
    else{
        printf("yanlis karakter bir daha deneyiniz...\n");
    }

    /*---------------bastigimiz resimler icin tuttugumuz alani geri bırakma--------------------*/
    al_destroy_display(display);
    al_destroy_bitmap(harita1);
    al_destroy_bitmap(harita2);
    al_destroy_bitmap(sagok);
    al_destroy_bitmap(solok);
    al_destroy_bitmap(xy);
    al_destroy_bitmap(yx);
    al_destroy_bitmap(zy);
    al_destroy_bitmap(yz);
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
            git:/*kabul edilemez bir deger icin donguyu dondurmeden bu isi halleder ve yoluna devam eder*/
            printf("%c yolu : ",anayol[i]);
            scanf("%d",&yolyonu);
            if(yolyonu==1 && k<2)/*2'den fazla 1 degeri verilememesi icin sayac tuttum*/
            {
                anayolyon[i]=1;
                k++;
            }
            else if(yolyonu==2 && l<2)
            {
                anayolyon[i]=-1;
                l++;
            }
            else if(yolyonu!=1 && yolyonu!=2)/* 2 deger harici giris yapilirsa*/
            {
                printf("bu degeri giremezsiniz.\n");
                goto git;/*etikete geri yollar  satir=228*/
            }
            else/*2'den fazla girislerde buraya gelir ve oldumu degiskenini degistirir ve bizde kontrolunu yapariz*/
            {
                oldumu=1;
            }
        }
        if(oldumu==1){
            printf("2 giris ve 2 cikis olmak zorunda.\n");
        }
    }while(oldumu!=0);/*fazladan girislerde basa geri yollar*/
    printf("bir sonraki asamaya gecebiliriz.\n\n\n");

    return anayolyon;/*anayol degerlerini dizi ile main'e yollar */
}


int **matrisolustur(int harita,int *anayol)
{
    int i,j;
    char bas,son;/*yon icin aldigimiz anayol isimleri*/
    int girisicikis[4];
    char arayolad[5]={'B','D','C','A','E'};
    char anayolad[4]={'x','y','z','t'};

    int **matris=(int**)malloc(4*sizeof(int*));//degerleri tutacagimiz matrisi mallocla sonradan aldik


    if(harita==1)//harita 1 icin yapilacak islemler
    {
        /*olusturulan matris icin sutun olusturma*/
        for(i=0;i<4;i++)
        {
            matris[i]=(int*)malloc(9*sizeof(int));
            girisicikis[i]=anayol[i];
            for(j=0;j<9;j++)
            {
                matris[i][j]=0;
            }
        }

        /*her yol icin dongu doner ve bu dongude dugumler uzerinden matrisi olusturduk*/
        for(i=0;i<4;i++)
        {
            basadon:/*bu etiket bir arayol icin verilemicek imkansiz olan yon durumunda gelir*/
            fflush(stdin);/*char degerleri karismamasi icin*/
            printf("\n%c yolu icin ;\n",arayolad[i]);
            printf("baslangic noktasi : ");
            scanf("%c",&bas);
            while('\n'!=getchar());//enter diger char degere atanmamasi icin kullandik
            printf("yonu : ");
            scanf("%c",&son);
            matris[i][i]=anayol[i];


            if(bas==anayolad[i])//baslangýc noktasi kontrolu yapiliyor sonra bunun uzerinden degerler verilecek
            {
                matris[i][i+4]=-1;/*saat yonunde oldugu zaman olur*/
                girisicikis[i]--;/*bu degisken sayesinde her dugum icin kesismeyi onleriz +3 veya -3 olmamaai gerekli*/
                if(girisicikis[i]<-2)/*kontrollerimi yaptim ve 3 ayni deger oldugunu buldum*/
                {
                    girisicikis[i]++;/*giris cikisi 1 eksilttim cunku burdan basa gittiginde bir kontrolden daha gececek*/
                    printf("bu yol icin bu yonu veremezsiniz.\n");
                    goto basadon;/*olamicak deger icin etikete gider*/
                }
                if(i==3)/*x icin dongunun basina dondugu icin 3'te ayri bir atama yapilmasi gerek*/
                {
                    matris[0][i+4]=1;
                    girisicikis[0]++;
                    if(girisicikis[0]>2)
                    {
                        girisicikis[0]--;
                        printf("bu yol icin bu yonu veremezsiniz.\n");
                        goto basadon;/*olamicak deger icin etikete gider*/
                    }
                }
                else if(i!=3)/*1 arayol icin 2 dugum oldugundan dongu donerken harf icin dongu degerini kaybetmeden diger degisiklikleride yapmis olduk*/
                {
                    matris[i+1][i+4]=1;
                    girisicikis[i+1]++;
                    if(girisicikis[i+1]>2)
                    {
                        girisicikis[i+1]--;
                        printf("bu yol icin bu yonu veremezsiniz.\n");
                        goto basadon;/*olamicak deger icin etikete gider*/
                    }
                }


            }

                /*---------------------------------------------------------------*/

            else//baslangic noktasi tam tersiyse oldugunda yapilacak islemler x,y gibi
            {
                /*yukaridaki kontrol durumunun aynini yapmis olduk*/
                matris[i][i+4]=1;
                girisicikis[i]++;
                if(girisicikis[i]>2)
                {
                    girisicikis[i]--;
                    printf("bu yol icin bu yonu veremezsiniz.\n");
                    goto basadon;
                }

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



    else if(harita == 2)/*eger mainden harita 2 bilgisi gelirse yapilacaklar*/
    {
        /*+1 arayolumuz oldugu icin her iki if blogu icinde ayri ayri matris olusturmus oldum*/
        for(i=0;i<4;i++)
        {
            matris[i]=(int*)malloc(10*sizeof(int));
            girisicikis[i]=anayol[i];
            for(j=0;j<10;j++)
            {
                matris[i][j]=0;

            }
            matris[i][i]=anayol[i];
        }


        for(i=0;i<5;i++)
        {
            basadoner:/*harita 2 icin olan etiketimizde bu,1.haritadaki kontrolun aynisi*/
            fflush(stdin);
            printf("\n%c yolu icin ;\n",arayolad[i]);
            printf("baslangic noktasi : ");
            scanf("%c",&bas);
            while('\n'!=getchar());
            printf("yonu : ");
            scanf("%c",&son);


            if(i!=4)/*dugumler uzerinden gittigim icin 4 onemli 5 olunca e oldugu bilinecek ve onu ayriyeten dolduracagim*/
            {

                /*burada yaptigimiz if else yapisi 1.haritadakiyle tamamamen ayni*/
                if(bas==anayolad[i])//baslangic noktasi kontrolu yapiliyor sonra bunun uzerinden degerler verilecek
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

                else//baslangic noktasi tam tersiyse yapilacaklar
                {
                    matris[i][i+4]=1;
                    girisicikis[i]++;
                    if(girisicikis[i]>2)
                    {
                        girisicikis[i]--;
                        printf("bu yol icin bu yonu veremezsiniz.\n");
                        goto basadoner;
                    }
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
            else/*artik i=5 oldu*/
            {
                if(bas=='t')
                {
                    matris[3][8]=-1;
                    matris[1][8]=1;

                }
                else{
                    matris[1][8]=-1;
                    matris[3][8]=1;
                }

            }
        }
        printf("\nevet...diger asamaya geciyoruz.\n\n");
    }

    return matris;/*matrisin son hali main'e gonderildi*/
}


int **yogunlukbul(int harita,int **sayimatrisi)
{
    int i,j,k=4;
    int yogunluk,oldumu=0;
    int **matris=(int**)malloc(4*sizeof(int*));
    int bilinmeyenkontrol=0;
    char arayolad[5]={'B','D','C','A','E'};
    char anayolad[4]={'x','y','z','t'};

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
            k=4;
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
        for(i=0;i<4;i++)
        {
            matris[i]=(int*)malloc(10*sizeof(int));

            for(j=0;j<10;j++)
            {
                matris[i][j]=sayimatrisi[i][j];
            }
        }
        printf("yollarin yogunluk degerlerini giriniz.\ndeger vermek istemiyorsaniz -1'e basin.\n");
        donus1://buraya don
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
            if(i!=4)
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
                            matris[i][9]=matris[i][9]-yogunluk;
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
            else if(i==4)
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
            k=4;
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

void gaussjordan(int satir,int sutun,int **matris)
{

    //int mat[4][9]={0,0,0,0,-1,0,0,0,-28,0,0,0,0,1,0,0,0,28,0,0,0,0,0,0,-1,0,-39,0,0,0,-1,0,0,1,0,50};

    int i,j,k,a,b;
    int tem;

    printf("\nGonderilen matris :: \n");
    for(i=0;i<satir;i++)
    {
        for(j=0;j<sutun;j++)
        {
            printf("%3d",matris[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");


    for(k=0;k<satir-1;k++)
    {

        if( (matris[k][k]) != 1)
        {
            int temp = matris[k][k];
            if(temp == 0)
                continue;
            for(j=0;j<sutun;j++)
            {
                matris[k][j] = ( (matris[k][j]) / temp );
            }
        }


        for(i=k+1;i<satir;i++)
        {
            tem = matris[i][k];
            for(j=k;j<sutun;j++)
            {

                matris[i][j] = matris[i][j] - ( matris[k][j] * tem );
            }

        }


        // Printing Each Step
        printf("\n**************************\n");
        if(k==satir-1)
            printf("Satir eselon formu : \n\n");
        else
            printf("Bolum %d\n\n",k+1);
        for(a=0;a<satir;a++)
        {
            for(b=0;b<sutun;b++)
            {
                if(matris[a][b] == -0)
                    matris[a][b] = 0;
                printf("%3d",matris[a][b]);
            }
            printf("\n");
        }
        printf("\n\n");
    }


    for (int n = 0; n <satir-1 ; ++n) {
        for (int i = n+1; i <satir ; ++i) {
            tem=matris[n][i];
            for (int j = 0; j <sutun ; ++j) {
                matris[n][j]-=tem*matris[i][j];
            }
        }
    }

    printf("Matrisin son hali ; \n");
    for(i=0;i<satir;i++)
    {
        for(j=0;j<sutun;j++)
        {
            printf("%3d",matris[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
