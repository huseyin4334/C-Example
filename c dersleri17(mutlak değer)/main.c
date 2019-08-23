#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int mutlak(int sayi)
 {

 if (sayi<0)
    sayi*=-1;
    return sayi;
}


int main()
{
    int number;
    printf("sayi giriniz:");
    scanf("%d",&number);
    printf("girdiginiz sayinin mutlak degeri:%d",mutlak (number));

    return 0;
}
