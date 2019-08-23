#include <stdio.h>
#include <stdlib.h>


void cati(){
printf("    /\\ \n");
printf("   /  \\ \n");
printf("  /    \\ \n");
printf(" /      \\ \n");
printf("/        \\ \n");

}
void duvar()
{
    printf("|        |\n");
    printf("|        |\n");
    printf("|        |\n");
    printf("|        |\n");
}
void taban()
{
    printf("----------\n");

}
int main()
{
    int i,kat_sayisi;
    printf("eviniz kac katli olsun:");
    scanf("%d",&kat_sayisi);
    cati();
    taban();
    for (i=0;i<kat_sayisi;i++)
    {
        duvar();
        taban();
    }


    return 0;
}
