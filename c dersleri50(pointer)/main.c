#include <stdio.h>
#include <stdlib.h>

/*void adres(char dizi1[],int n)
{
    int i;
    int x;
    for (i=0;n>i;i++)
    {
        printf("%c   %p\n",dizi1[i],dizi1+i);
    }
    printf("4'e modu sifir olanlar\n");
    for (i=0;n>i;i++)
    {
        x=dizi1+i;
        if((x)%2==0)
            printf("%c   %p\n",dizi1[i],dizi1+i);
    }
}

int main()
{
    char dizi[100];
    int i,j;
    printf("dizi boyutunu giriniz:");
    scanf("%d",&j);

    for (i=0;j>i;i++)
    {
        printf("dizinin %d.elemanini giriniz:",i+1);
        scanf("%s",&dizi[i]);
    }

adres(dizi,j);
return 0;
}*/
void saat_cevir(int toplam_saniye, int *saat, int *dk, int *sn) {
    *sn = toplam_saniye % 60;

    *dk = (toplam_saniye / 60) % 60;

    *saat = (toplam_saniye / 3600);
}

int main() {
while (1) {
int saat, dakika, saniye;
    int girilen_sayi;

// kullanicidan bir sayi istiyoruz
    printf("sayi girin: ");
    scanf("%d", &girilen_sayi);

// fonksiyona girilen_sayi'yi ve
    // saat, dakika, saniye degiskenlerinin adreslerini gonderiyoruz
    saat_cevir(girilen_sayi, &saat, &dakika, &saniye);

printf("%d saat %d dakika %d saniye\n\n", saat, dakika, saniye);
}

return 0;
}

