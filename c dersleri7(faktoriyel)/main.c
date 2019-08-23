#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int fact=1;
    printf("sayi giriniz:");
    scanf("%d",&n);

    while(n!=0)
    {
        fact=fact*n;
        n--;
    }
    printf("%d",fact);
    return 0;
}
