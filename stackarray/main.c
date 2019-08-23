#include <stdio.h>
#include <stdlib.h>

int *dizi=NULL;
int boyut=2;
int tepe=0;


int pop()
{
    if(dizi==NULL)
    {
        printf("bu dizi bos\n");
        return -1;
    }
    if(tepe<=boyut/4)
    {
        int *dizi2=(int*)malloc(sizeof(int)*boyut/2);
        for(int i=0;i<boyut;i++)
        {
            dizi2[i]=dizi[i];
        }
        free(dizi);
        dizi=dizi2;
        boyut/=2;
    }
    return dizi[--tepe];
}



void push(int a)
{
    if(dizi==NULL)
    {
        dizi=(int*)malloc(sizeof(int)*2);
    }
    if(tepe>=boyut)
    {
        int *dizi2=(int*)malloc(sizeof(int)*boyut*2);
        for(int i=0;i<boyut;i++)
        {
            dizi2[i]=dizi[i];
        }
        free(dizi);
        dizi=dizi2;
        boyut*=2;
    }
    dizi[tepe++]=a;
}


void bastir()
{
    printf("%d\n",boyut);
    for(int i=0;i<tepe;i++)
    {
        printf("%d\t",dizi[i]);
    }
    printf("\n\n");
}

int main()
{
    push(10);
    push(20);
    push(40);
    push(100);
    push(2);
    push(4);
    push(34);
    bastir();
    printf("popped %d\n",pop());
    bastir();
    printf("popped %d\n",pop());
    bastir();
    printf("popped %d\n",pop());
    bastir();
    printf("popped %d\n",pop());
    bastir();
    printf("popped %d\n",pop());
    bastir();
    push(32);
    push(100);
    push(45);
    push(98);
    push(54);
    push(12);
    push(44);
    push(75);
    push(68);
    push(77);
    push(32);
    push(100);
    push(45);
    push(98);
    push(54);
    bastir();




   // printf("popped %d\n",pop());
   // printf("popped %d\n",pop());
    return 0;
}
