#include <stdio.h>
#include <stdlib.h>

struct dugum
{
    int x;
    struct dugum *next;
};



void bastir(struct dugum *r)
{
    while(r!=NULL)
    {
        printf("%d\t",r->x);
        r=r->next;
    }
    printf("\n");
}



void ekle(struct dugum *r,int sayi)
{
    while(r->next!=NULL)
    {
        r=r->next;
    }
    r->next=(struct dugum*)malloc(sizeof(struct dugum));
    r->next->x=sayi;
    r->next->next=NULL;
}




struct dugum *siraliekle(struct dugum *r,int sayi)
{
    /*link list bos ise.*/
    if(r==NULL)
    {
        r=(struct dugum *)malloc(sizeof(struct dugum));
        r->next=NULL;
        r->x=sayi;
        return r;
    }

    /*bu if durumu rootu degistirir.ozel durumdur.*/
    if(r->x > sayi)
    {
        struct dugum *temp = (struct dugum*)malloc(sizeof(struct dugum));
        temp ->x = sayi;
        temp->next=r;
        return temp;
    }

    /*link listin  herhangi bir yerine eklemme yapmak.*/
    struct dugum *iter=r;
    while(iter->next!=NULL && iter->next->x < sayi)
    {
        iter=iter->next;
    }
    struct dugum *temp = (struct dugum*)malloc(sizeof(struct dugum));
    temp->next=iter->next;
    iter->next=temp;
    temp->x=sayi;
    return r;

}





struct dugum *sil(struct dugum *r,int sayi)
{
    struct dugum *temp;
    struct dugum *iter=r;
    if(r->x==sayi)
    {
        temp=r;
        r=r->next;
        free(temp);
        return r;
    }
    while(iter->next!=NULL && iter->next->x != sayi)
    {
        iter=iter->next;
    }
    if(iter->next==NULL)
    {
        printf("sayi bulunamadi.\n");
        return r;
    }
    temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
    return r;
}


int main()
{
    /*dongu ile eleman ekleme yontemi*/
    struct dugum *root;
    root=NULL;
    root=siraliekle(root,300);
    root=siraliekle(root,40);
    root=siraliekle(root,440);
    root=siraliekle(root,10);
    root=siraliekle(root,50);
    root=siraliekle(root,20);
    root=siraliekle(root,220);
    root=siraliekle(root,1);
    bastir(root);
    /*root=(struct dugum*)malloc(sizeof(struct dugum));
    root->x=0;
    root->next=NULL;*/
    /*int i;
    for(i=1;i<6;i++)
    {
        ekle(root,i*10);
    }
    bastir(root);

    /*araya deger ekleme dongusu*/
    /*struct dugum *iter=root;
    for(i=0;i<3;i++)
    {
        iter=iter->next;
    }
    struct dugum *temp=(struct dugum*)malloc(sizeof(struct dugum));
    temp->next=iter->next;
    iter->next=temp;
    temp->x=100;
    bastir(root);*/







    return 0;
}
