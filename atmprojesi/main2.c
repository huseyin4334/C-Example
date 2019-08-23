#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct urunbilgileri{
    int urunId;
    char urunAdi[10];
    int stok;
    float urunFiyat;
};


/*--------------Kullanicilerin yaptigi secimleri dinamiklestirdik---------------*/

struct dugum{
    int x;
    struct dugum *next;
};


struct dugum *ekle(struct dugum *iter,int sayi){

    struct dugum *r=iter;
    if(r==NULL)
    {
        r=(struct dugum *)malloc(sizeof(struct dugum));
        r->next=NULL;
        r->x=sayi;
    }
    else{
        while(r->next!=NULL)
        {
            r=r->next;
        }
        r->next=(struct dugum*)malloc(sizeof(struct dugum));
        r->next->x=sayi;
        r->next->next=NULL;
    }
    return iter;
}

/*--------------Kullanicilerin yaptigi secimleri dinamiklestirdik---------------*/



int main()
{
    /*0 : 25 kurus, 1 : 50 kurus, 2 : 1 TL*/
    float bakiye; // kullanicini toplam parasi;
    int buton; //kullanicinin basacagi butonlar
    float bozukpara[]={0,0,0}; //kasadaki paralar
    float kullaniciparasi[3]; //kullanicinin attýðý paralarýn adetleri
    struct urunbilgileri urunler[5]; //urunler icin olusturulmus nesneler


    /*----------stringin yorumlanmasý ve degerlerin yerine yazýlmasý--------------*/
    for(int i=0;i<5;i++){
    //sscanf( dtm, "%s %s %d  %d", weekday, month, &day, &year );

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

    int randomsayi; //makinenin bozulma olasiligi
    struct dugum *root; //secimlerin dinamik sekilde yapilmasi
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
            for(int i=0;i<5;i++){
                if(buton == urunler[i].urunId){
                    if(bakiye >= urunler[i].urunFiyat){
                        bakiye-=urunler[i].urunFiyat;
                        printf("kalan bakiye %.2f TL",bakiye);
                        root=ekle(root,urunler[i].urunId);
                    }
                    else{
                        printf("bakiye yetersiz..");
                    }
                }
            }
        }
    }while(buton!=6);

/*-----------------------Kullaniciya secim yaptirma bolumu-----------------------*/



/*---------------------Kartýn calýsma veya bozulma durumu-----------------------*/
    randomsayi = rand()%4+1;
    if(randomsayi==2){
        bakiye=0.0;
        printf("para takildi..");
        printf("kirmizi led yanacak..");
        printf("reset tusuna bas(7) : ");
        scanf("%d",&buton);
        if(buton==7){
            goto reset;
        }
    }
    else{
        printf("yesil led yanacak..");
        for(int i=0;i<3;i++){
            bozukpara[i]+=kullaniciparasi[i];
        }
        while(root!=NULL){
            urunler[(root->x)-1].stok--;
            root=root->next;
        }
    }

/*---------------------Kartýn calýsma veya bozulma durumu-----------------------*/



/*---------------------------Para iadesi bolumu-------------------------------*/
while(bakiye!=0.0){

}
/*---------------------------Para iadesi bolumu-------------------------------*/
    return 0;
}
