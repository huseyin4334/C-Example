#include <stdio.h>
#include <stdlib.h>
int factorial(int sayi);
int fibonacci(int sayi);
int main()
{
    /*
    --------------faktoriyel ornegi-------------------
    int sayi=0;
    printf("%d",factorial(sayi));
    */


    function(8);

    return 0;
}



int factorial(int sayi)
{
    if(sayi==0)
        return 1;
    else
        return sayi*factorial(sayi-1);
}

int fibonacci(int sayi)
{

}

int function(int sayi)
{
    printf("%d\t",sayi);
    if(sayi<1)
        return;
    printf("%d ",sayi);//bu fonksiyondan once yazildigi icin fok. cgýrýlmadan yazdýrýlýr.
    function(sayi-1);
    printf("%d\n",sayi);//bu fonksiyondan sonra yazildigi icin fok.daki degerler sonuclanana kadar yazýlmaz
    //sonuclandýgýnda sondan basa dogru yazmaya baslar.


}
