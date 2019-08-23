#include <stdio.h>
#include <stdlib.h>

struct dugum
{
    int sayi;
    struct dugum *pointer;
};


void bastir(struct dugum *r)
{
    while(r!=NULL)
    {
        printf("%d\n",r->sayi);
        r=r->pointer;
    }
}






int main()
{
    struct dugum *root;
    root=(struct dugum*)malloc(sizeof(struct dugum));//root pointerini olusturduk.
    root->sayi=10;//root'un datasina 10 atadik
    root->pointer=(struct dugum*)malloc(sizeof(struct dugum));//root'un bir sonrakini gostermesi icin yeni olusan alaný tutar.
    root->pointer->sayi=20;
    root->pointer->pointer=NULL;
    //genel mantik budur.
    struct dugum *temp;//temp sayesinde bu liste uzerinde ilerleyebiliriz.
    temp=root;
    int i=0;
    for(i=0;i<5;i++)
    {
        temp->pointer=(struct dugum*)malloc(sizeof(struct dugum));
        temp=temp->pointer;
        temp->sayi=i*10;
        temp->pointer=NULL;
    }
    bastir(root);

    return 0;
}
