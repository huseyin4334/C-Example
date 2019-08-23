#include <stdio.h>
#include <stdlib.h>

void dortbasamak(int sayi){
    int temp=sayi;
    int rakamlar[4];
    int i=0;
    while(sayi!=0){
        rakamlar[i]=sayi%10;
        sayi/=10;
    }
    if(temp == ((rakamlar[3]*rakamlar[2])+(rakamlar[1]*rakamlar[1]))*((rakamlar[3]*rakamlar[2])+(rakamlar[1]*rakamlar[1])))
        printf("%d",temp);
}
