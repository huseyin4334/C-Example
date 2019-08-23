#include <stdio.h>
#include <stdlib.h>

void dortbasamak(){
    int temp;
    int rakamlar[4];
    int i=0;
    for(int sayi=1000;sayi<9999;sayi++){
        temp=sayi;
        while(sayi!=0){
        rakamlar[i]=sayi%10;
        sayi/=10;
        }
        if(temp == ((rakamlar[3]*rakamlar[2])+(rakamlar[1]*rakamlar[1]))*((rakamlar[3]*rakamlar[2])+(rakamlar[1]*rakamlar[1])))
            printf("%d",temp);
    }
    sayi=temp;
}
