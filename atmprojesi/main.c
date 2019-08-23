#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct urunbilgileri{
    int urunId;
    char urunAdi[10];
    int stok;
    float urunFiyat;
    struct urunbilgileri *next;
};

struct dugum{
    int x;
    struct dugum *next;
};

/*--------------Kullanicilerin yaptigi secimleri dinamiklestirdik---------------*/


struct dugum *siparisekle(struct dugum *iter,int sayi){

    struct dugum *r=iter;
    if(r==NULL)
    {
        r=(struct dugum *)malloc(sizeof(struct dugum));
        r->next=NULL;
        r->x=sayi;
        return r;
    }
    else{
        while(r->next!=NULL)
        {
            r=r->next;
        }
        r->next=(struct dugum*)malloc(sizeof(struct dugum));
        r->next->x=sayi;
        r->next->next=NULL;
        return iter;
    }

}


struct urunbilgileri *urunekle(struct urunbilgileri *iter,char uruntemp[]){

    int urunId;
    char urunAdi[10];
    int stok;
    float urunFiyat;
    char * pch;

    pch = strtok (uruntemp,",");
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


    struct urunbilgileri *r=iter;
    if(r==NULL)
    {
        r=(struct urunbilgileri *)malloc(sizeof(struct urunbilgileri));
        r->next=NULL;
        r->urunId=urunId;
        sscanf(urunAdi,"%s",r->urunAdi);
        r->stok=stok;
        r->urunFiyat=urunFiyat;
        return r;
    }
    else{
        while(r->next!=NULL)
        {
            r=r->next;
        }

        r->next=(struct urunbilgileri*)malloc(sizeof(struct urunbilgileri));
        r->next->next=NULL;
        r->next->urunId=urunId;
        sscanf(urunAdi,"%s",r->urunAdi);
        r->next->stok=stok;
        r->next->urunFiyat=urunFiyat;
        return iter;
    }
}
/*--------------Urunlerin kaydedilmesi ve Kullanicilerin yaptigi secimleri dinamiklestirdik---------------*/






int main()
{
    /*0 : 25 kurus, 1 : 50 kurus, 2 : 1 TL*/
    float bakiye; // kullanicini toplam parasi;
    char para[]="20,20,10";
    char urunler[5][25]={"1,su,30,0.5","2,cay,20,1","3,kahve,15,1.5","4,cikolata,50,1.75","5,biskuvi,100,2"};
    char uruntemp[15];
    int buton; //kullanicinin basacagi butonlar
    int bozukpara[3]; //kasadaki paralar
    int kullaniciparasi[3]; //kullanicinin attýðý paralarýn adetleri
    struct urunbilgileri *urun; //urunler icin olusturulmus nesneler
    urun=NULL;
    struct urunbilgileri *iter; //urunler uzerinde hareketi saglar
    int randomsayi; //makinenin bozulma olasiligi
    struct dugum *root; //secimlerin dinamik sekilde yapilmasi




    /*----------stringin yorumlanmasý ve degerlerin yerine yazýlmasý--------------*/
    sscanf(para, "%d,%d,%d", &bozukpara[0], &bozukpara[1], &bozukpara[2]);

    for(int i=0;i<5;i++){
        sscanf(urunler[i], "%s", uruntemp);
        urun=urunekle(urun,uruntemp);
    }

    /*--------stringin yorumlanmasý ve degerlerin yerine yazýlmasý---------------*/






    reset:// goto komutunun kipi
    bakiye = 0.0; //reset atilinca degerler sifirla yeniden basla
    for(int i=0;i<3;i++){
        kullaniciparasi[i]=0;
    }
    /*--------------------kullanýcýdan para alma bolumu-------------------------*/
    do{
        printf("para atiniz : ");
        scanf("%d",&buton);

        switch(buton){
        case 1:
            kullaniciparasi[0]++;
            bakiye+=0.25;
            break;
        case 2:
            kullaniciparasi[1]++;
            bakiye+=0.5;
            break;
        case 3:
            kullaniciparasi[2]++;
            bakiye+=1.0;
            break;
        case 4:
            break;
        }
    }while(buton!=4);
    /*--------------------kullanýcýdan para alma bolumu-------------------------*/





    /*-----------------------Kullaniciya secim yaptirma bolumu-----------------------*/
    printf("\n%.2f TL para attiniz.",bakiye);

    root=NULL;

    printf("\n");
    do{

        printf("urunlerinizi secin : ");
        scanf("%d",&buton);

        if(buton == 7){
            printf("herþey resetlendi");
            bakiye=0.0;
            goto reset;
        }

        else if(bakiye!=0.0 && buton!=6){
            iter=urun;
            while(iter!=NULL){
                if(buton == iter->urunId){
                    if(bakiye >= iter->urunFiyat){
                        bakiye-=iter->urunFiyat;
                        printf("kalan bakiye %.2f TL\n",bakiye);
                        root=siparisekle(root,iter->urunId);
                    }
                    else{
                        printf("bakiye yetersiz..\n");
                    }
                }
                iter=iter->next;
            }
        }
        else if(bakiye==0.0&& buton!=6){
            printf("bakiye yetersiz..\nSiparislerinizi resetleyebilir yada devam edebilirsiniz\n");
        }
    }while(buton!=6);

/*-----------------------Kullaniciya secim yaptirma bolumu-----------------------*/




/*---------------------Kartýn calýsma veya bozulma durumu-----------------------*/
    randomsayi = rand()%4+1;
    if(randomsayi==2){
        bakiye=0.0;
        printf("para takildi..\n");
        printf("kirmizi led yanacak..\n");
        printf("reset tusuna bas(7) : ");
        scanf("%d",&buton);
        if(buton==7){
            goto reset;
        }
    }
    else{
        printf("yesil led yanacak..\n");
        for(int i=0;i<3;i++){
            bozukpara[i]+=kullaniciparasi[i];
        }
        /*---------------degisti---------*/
        while(root!=NULL){
            iter=urun;
            while(iter->urunId!=(root->x)){
                iter=iter->next;
            }
            iter->stok--;
            root=root->next;
        }

        /*------------degisti-------------------*/

        int kurusadet=0;
        int ellikurus;
        int birtl;
        while(bakiye!=0.0){
            kurusadet++;
            bakiye-=0.25;
        }

        if(kurusadet!=0){
            birtl=kurusadet/4;
            kurusadet=kurusadet%4;
            ellikurus=kurusadet/2;
            kurusadet=kurusadet%2;

            if(birtl!=0){
                if(bozukpara[2]>=birtl){
                }
                else{
                    birtl-=bozukpara[2];
                    ellikurus+=(birtl*2);
                    birtl=0;
                }
            }
            if(ellikurus!=0){
                if(bozukpara[1]>=ellikurus){
                }
                else{
                    ellikurus-=bozukpara[1];
                    kurusadet+=(ellikurus*2);
                    ellikurus=0;
                }
            }
            if(kurusadet!=0){
                if(bozukpara[0]>=kurusadet){
                    bozukpara[2]-=birtl;
                    bozukpara[1]-=ellikurus;
                    bozukpara[0]-=kurusadet;
                    printf("%d-%d-%d\n",bozukpara[0],bozukpara[1],bozukpara[2]);
                /*---------------degisti---------*/
                /*while(root!=NULL){
                    iter=urun;
                    while(iter->urunId!=(root->x)){
                        iter=iter->next;
                    }
                    iter->stok--;
                    root=root->next;
                }*/

                /*------------degisti-------------------*/
                    printf("islem tamam\n");
                }
                else{
                    printf("Yeterli para bulunmamaktadir\n");
                    for(int i=0;i<3;i++){
                        bozukpara[i]-=kullaniciparasi[i];
                    }
                }
            }
        }

        printf("basla tekrar\n");
        goto reset;
    }


/*---------------------Kartýn calýsma veya bozulma durumu-----------------------*/


    return 0;
}
