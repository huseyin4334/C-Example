#include <stdio.h>
#include <stdlib.h>

struct dugum
{
    int x;
    struct dugum *next;
};

/*DAÝRESEL BAGLI LÝSTE*/

void bastir(struct dugum *r)
{
    struct dugum *iter=r;
    printf("%d\t",r->x);
    iter=iter->next;
    while(iter!=r)
    {
        printf("%d\t",iter->x);
        iter=iter->next;
    }
    printf("\n");
}



void ekle(struct dugum *r,int sayi)
{
    struct dugum *iter=r;
    while(iter->next!=r)
    {
        iter=iter->next;
    }
    iter->next=(struct dugum*)malloc(sizeof(struct dugum));
    iter->next->x=sayi;
    iter->next->next=r;
}




struct dugum *siraliekle(struct dugum *r,int sayi)
{
    /*link list bos ise.*/
    if(r==NULL)
    {
        r=(struct dugum *)malloc(sizeof(struct dugum));
        r->next=r;
        r->x=sayi;
        return r;
    }

    /*bu if durumu rootu degistirir.ozel durumdur.*/
    if(r->x > sayi)
    {
        struct dugum *temp = (struct dugum*)malloc(sizeof(struct dugum));
        temp ->x = sayi;
        temp->next=r;
        struct dugum *iter=r;
        while(iter->next!=r)
            iter=iter->next;
        iter->next=temp;
        return temp;
    }

    /*dosyanýn herhangi bir yerine eklemme yapmak.*/
    struct dugum *iter=r;
    while(iter->next!=r && iter->next->x < sayi)
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
        while(iter->next!=r)
            iter=iter->next;
        iter->next=r->next;

        free(r);
        return iter->next;
    }

    while(iter->next!=r && iter->next->x != sayi)
    {
        iter=iter->next;
    }
    if(iter->next==r)
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
   bastir(root);
    root=siraliekle(root,40);
   bastir(root);
    root=siraliekle(root,440);
    bastir(root);
    root=siraliekle(root,10);
    bastir(root);
    root=siraliekle(root,50);
    bastir(root);
    root=siraliekle(root,20);
    bastir(root);
    root=siraliekle(root,220);
    bastir(root);
    root=siraliekle(root,1);
    bastir(root);
    root=sil(root,20);
    bastir(root);
    root=sil(root,220);
    bastir(root);
    root=sil(root,1);
    bastir(root);








    return 0;
}
