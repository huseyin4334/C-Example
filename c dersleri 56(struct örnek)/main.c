#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct zaman{
int saat;
int dakika;
int saniye;
};
struct personel{
char name[30];
struct zaman sure;
int calismasuresi;
};
int main()
{
    int i,j;
    int N;
    char dizi[10];
    /*int enbuyuk=0;
    int enb=0;*/

    printf("calisan sayisini giriniz:");
    scanf("%d",&N);
    struct personel *employelist=(struct personel*)malloc(N*sizeof(struct personel));
    printf("calisanlarinizin bilgilerini giriniz:\n");
    while(getchar()!='\n');
    for(i=0;i<N;i++)
    {
        printf("calisanin adi:");
        gets(employelist[i].name);
        printf("calisanin haftalik calisma suresini yaziniz(saat saniye dakika):");
        fgets(dizi,10,stdin);
        sscanf(dizi,"%d %d %d",&employelist[i].sure.saat,&employelist[i].sure.dakika,&employelist[i].sure.saniye);
        employelist[i].calismasuresi=60*60*employelist[i].sure.saat+60*employelist[i].sure.dakika+employelist[i].sure.saniye;
        /*if(employelist[i].calismasuresi>enbuyuk){
            enbuyuk=employelist[i].calismasuresi;
            enb=i;
            }*/
    }
    struct personel kisi;
    printf("bu haftanin en cok calisanlar listesi:\n");
    printf("|isim                |saat|dakika|saniye|total |\n");
    printf("------------------------------------------------\n");
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(employelist[j].calismasuresi>employelist[i].calismasuresi)
            {
                kisi=employelist[i];
                employelist[i]=employelist[j];
                employelist[j]=kisi;
            }
        }
    }
    for(i=0;i<N;i++)
    {
        printf("|%-20s|%-4d|%-6d|%-6d|%-6d|",employelist[i].name,employelist[i].sure.saat,employelist[i].sure.dakika,employelist[i].sure.saniye,employelist[i].calismasuresi);
        printf("\n");
        printf("------------------------------------------------\n");

    }
    printf("Performansýnýzdan dolayý sizleri tebrik ediyoruz...");
    free(employelist);
    return 0;
}
