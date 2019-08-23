#include <stdio.h>
#include <stdlib.h>


/*void yaz(int *d,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",d[i]);
    }
    printf("\n");
}

int main()
{
int i;
int N = 5;
	int *dizi = (int*)malloc(N * sizeof(int));
		dizi[0] = 5;
        dizi[1] = 2;
        dizi[2] = 3;
        dizi[3] = 8;
        dizi[4] = 4;
        int yeni=11;
        N++;
        dizi=(int*)realloc(dizi,N*sizeof(int));
        dizi[N-1]=yeni;
        printf("sona eklendiginde: ");
        yaz(dizi,N);
        N--;
        dizi = (int*)realloc(dizi, N * sizeof(int));
        printf("sondan silindiginde: ");
        yaz(dizi,N);


    return 0;
}*/










struct koordinat{
int x;
int y;
int bolge;
struct koordinat *adres;
};
int main()
{
    int i;
    int N=50;
    struct koordinat *nokta1=(struct koordinat*)malloc(N*sizeof(struct koordinat));
    for(i=0;;i++)
    {
        printf("sonucu ekrana yazdýrmak icin x veya y den en az birini 0 girin.\n");
        printf("%d. noktanin x degerini girin:",i+1);
        scanf("%d",&nokta1[i].x);
        printf("%d. noktanin y degerini girin:",i+1);
        scanf("%d",&nokta1[i].y);
        if(nokta1[i].x==0 || nokta1[i].y==0)
        {

            nokta1[i-1].adres=NULL;
            break;
        }
        if(nokta1[i].x>0 && nokta1[i].y>0)
        {
            nokta1[i].bolge=1;
        }
        else if(nokta1[i].x<0 && nokta1[i].y>0)
        {
            nokta1[i].bolge=2;
        }
        else if(nokta1[i].x<0 && nokta1[i].y<0)
        {
            nokta1[i].bolge=3;
        }
        else if(nokta1[i].x>0 && nokta1[i].y<0)
        {
            nokta1[i].bolge=4;
        }

        nokta1[i].adres=&nokta1[i+1];
        nokta1[N-1].adres=NULL;
    }
    N=i;
    nokta1=(struct koordinat*)realloc(nokta1,N*sizeof(struct koordinat));
    struct koordinat *strptr=nokta1;
    while(strptr!=NULL)
    {
        printf("%-3d %-3d %-3d\n",strptr->x,strptr->y,strptr->bolge);
        strptr=strptr->adres;
    }

    free(nokta1);
    return 0;
}









