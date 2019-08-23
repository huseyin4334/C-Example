#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int x=0xAD12;
    int *p;
    p=&x;
    printf("%p\n",x);
    printf("%p\n",*p);
    *p=0x390;
    printf("%p\n",x);*/





        /*int i;
    	int dizi[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    	printf("dizi: ");
    		for (i = 0 ; i < 10 ; i++)
                printf("%d ", dizi[i]);
            printf("\n\n");


            char *s = (char*)(dizi);


            strcpy(s, "test aaaabbbb");
            printf("s: %s\n\n", s);
            printf("dizi: ");
    		for (i = 0 ; i < 10 ; i++)
            printf("%d ", dizi[i]);
            printf("\n\n");*/





        int *A;
        A=(int*)malloc(sizeof(int));
        printf("Anýn gosterdigi deger:%d\n\n",*A);
        *A=123,
        printf("Anýn tuttugu deger:%d",*A);
    return 0;
}
