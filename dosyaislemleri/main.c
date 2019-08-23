#include <stdio.h>
#include <stdlib.h>

int main()
{
      int i=12,j;
      float x=2.345,y;
      char ch="a",ck;
      FILE *deneme1,*deneme2;

    /*
        w=yazma.varsa dosyanin ustune yazar.yoksa olusturur.
        w+= yazma ve okuma.varsa dosyanin ustune yazar.yoksa olusturur.dosyanin basini gosterir.
        r=okuma.varsa dosyayi okur.yoksa hata verir.
        r+= yazma ve okuma.yoksa olusturur.dosyanin basini gosterir.
        a=ekleme.varsa dosyanin sonuna yazar.yoksa olusturur.
        a+= ekleme ve okuma.varsa dosyanin sonunu gosterir.
    */
    deneme1=fopen("ilkadim.txt","w");
    fprintf(deneme1,"%d %f %c",i,x,ch);//egerleri deneme ointerý aracýlýgýyla ilkadim.txt'nin icine yazdik.
    fclose(deneme1);
    deneme2=fopen("ilkadim.txt","r");
    fscanf(deneme2,"%d %f %c",&j,&y,&ck);//degerleri deneme ointerý aracýlýgýyla ilkadim.txt'nin icine yazdik.
    //fclose(deneme2);
    printf("%d %.3f %c\n",i,x,ch);
    printf("%d %.3f %c\n",j,y,ck);
    return 0;
}
