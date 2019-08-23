#include <stdio.h>
#include <stdlib.h>

struct dugum
{
    int data;
    struct dugum *next;
};
void bastir(struct dugum *r)
{
    while(r!=NULL)
    {
        printf("%d\t",r->data);
        r=r->next;
    }
    printf("\n");
}
int pop(struct dugum *r)
{
    if(r==NULL)
    {
        printf("stack bos.\n");
        return -1;
    }
    if(r->next==NULL)
    {
        int value=r->data;
        r=NULL;
        return value;
    }
    struct dugum *iter=r;
    while(iter->next->next!=NULL)
    {

        iter=iter->next;
    }
    struct dugum *temp = iter->next;
    int value=temp->data;
    iter->next=NULL;
    free(temp);
    return value;
}
struct dugum *push(struct dugum *r,int x)
{
    if(r==NULL)
    {
        r=(struct dugum*)malloc(sizeof(struct dugum));
        r->data=x;
        r->next=NULL;
        return r;
    }
    struct dugum *iter =r;
    while(iter->next!=NULL)
    {
        iter=iter->next;
    }
    struct dugum *temp = (struct dugum*)malloc(sizeof(struct dugum));
    temp->data=x;
    temp->next=NULL;
    iter->next=temp;
    return r;
}




int main()
{
    struct dugum *s=NULL;
    s=push(s,10);
    s=push(s,23);
    s=push(s,21);
    s=push(s,12);
    s=push(s,89);
    s=push(s,77);
    bastir(s);
    printf("%d\n",pop(s));
    bastir(s);
    printf("%d\n",pop(s));
    bastir(s);
    printf("%d\n",pop(s));
    bastir(s);
    return 0;
}
