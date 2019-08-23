#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *sol;
struct node *sag;
};
struct node *yeninode(int data)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->sol = temp->sag = NULL;
    return temp;
}
struct node* insert(struct node *agac,int data)
{
    if(agac==NULL)
    {
        struct node *temp =  (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->sol = temp->sag = NULL;
        return temp;
    }
    if((agac->data)< data)
        agac->sag=insert(agac->sag,data);

    else
        agac->sol=insert(agac->sol,data);

    return agac;
}



void inorder(struct node *agac)
{
    if(agac==NULL)
        return;

    else
    {
        inorder(agac->sol);
        printf("%d ",agac->data);
        inorder(agac->sag);
    }


}

void preorder(struct node *agac)
{
    if(agac!=NULL)
    {
        printf("%d ",agac->data);
        preorder(agac->sol);
        preorder(agac->sag);
    }
    else
        return;

}

void postorder(struct node *agac)
{
    if(agac!=NULL)
    {
        postorder(agac->sag);
        printf("%d ",agac->data);
        postorder(agac->sol);

    }
    else
        return;

}

int bul(struct node *agac,int aranan)
{
    if(agac==NULL)
        return -1;
    if(agac->data==aranan)
        return 1;
    if(bul(agac->sag,aranan)==1)
        return 1;
    if(bul(agac->sol,aranan)==1)
        return 1;
    return -1;
}


int max(struct node *agac)
{
    while(agac->sag!=NULL)
        agac=agac->sag;
    return agac->data;
}
int min(struct node *agac)
{
    while(agac->sol!=NULL)
        agac=agac->sol;
    return agac->data;
}


struct node* delete(struct node *agac,int data)
{
    if(agac==NULL)
        return NULL;
    if(agac->data==data)
    {
        if(agac->sol==NULL && agac->sag==NULL)
            return NULL;
        if(agac->sag!=NULL){
            agac->data=min(agac->sag);
            agac->sag=delete(agac->sag,min(agac->sag));
            return agac;
        }
        else{
            agac->data=max(agac->sol);
            agac->sol=delete(agac->sol,max(agac->sol));
            return agac;
        }
    }

    if(agac->data<data)
        agac->sag=delete(agac->sag,data);

    else
        agac->sol=delete(agac->sol,data);
    return agac;
}



int main()
{
    struct node *agac=NULL;
    int sayi;

    printf("\nEleman sayisini giriniz : ");
    scanf("%d",&sayi);
    for(int i=0;i<sayi;i++){
        printf("\n%d.sayiyi giriniz : ",i+1);
        int deger;
        scanf("%d",&deger);
        agac=insert(agac,deger);
    }

    /*agac=insert(agac,200);
    agac=insert(agac,190);
    agac=insert(agac,56);
    agac=insert(agac,24);
    agac=insert(agac,213);
    agac=insert(agac,18);
    agac=insert(agac,27);
    agac=insert(agac,28);*/

    printf("inorder : ");
    inorder(agac);
    printf("\n\npreorder : ");
    preorder(agac);
    printf("\n\npostorder : ");
    postorder(agac);
    printf("\n\nAgactaki en kucuk sayi : %d",min(agac));

    printf("\n\nAgactaki en buyuk sayi : %d",max(agac));

    printf("\n\nsilinecek sayiyi giriniz : ");
    scanf("%d",&sayi);
    agac=delete(agac,sayi);
    printf("\n\ninorder : ");
    inorder(agac);
    while(1){
        printf("\n\naramak icin bir sayi giriniz : ");
        scanf("%d",&sayi);
        if(sayi==-1)
            break;
        if(bul(agac,sayi)==1)
            printf("bu sayi agacimizda vardir.");
        else
            printf("bu sayi agacimizda yoktur.");


    }

    return 0;
}
