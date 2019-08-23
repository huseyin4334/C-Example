#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <ozelsayi.h>
int main()
{
    /*1.Ödev*/
    /*int yukseklik,taban_alani,alan;
    printf("Yukseklik giriniz : ");
    scanf("%d",&yukseklik);
    printf("\nTaban Alani giriniz : ");
    scanf("%d",&taban_alani);
    alan=(taban_alani*yukseklik)/2;
    printf("\nUcgenin alani : %d",alan);*/



    /*2.Ödev*/
    /*int sayi;
    int rakam;
    int temp,basamak=0;
    printf("Bir sayi giriniz : ");
    scanf("%d",&sayi);
    temp=sayi;
    while(temp!=0){
        temp=temp/10;
        basamak=basamak+1;
    }
    while(basamak!=0){
        temp=1;
        for(int i=0;i<basamak-1;i++){
            temp*=10;
        }
        rakam=sayi/temp;
        printf("%d",rakam);
        for(int i=0;i<rakam;i++){
            printf("*");
        }
        sayi=sayi%temp;
        basamak--;
    }*/



    /*3.Ödev*/
    /*int dongu;
    int toplam;
    int rand1,rand2;
    printf("Kac kez denemek istersiniz : ");
    scanf("%d",&dongu);
    for(int i=0;i<dongu;i++){
        rand1=rand()%5+1;
        rand2=rand()%5+1;
        toplam=rand1+rand2;
        printf("%d : %d ",i+1,toplam);
        for(int j=0;j<toplam;j++){
            printf("*");
        }
        printf("\n");
    }*/


    /*4.Ödev*/

//dortbasamak();





	int size =4,i,j,k;
	int arr[]={1,2,1,1};
	i=0;
	do{
		j=i+1;
		do{
			if(arr[i]==arr[j]){
				k=j;
				printf("--------%d-%d-----\n",k,size);
				do{
                    printf("%d-%d-%d\n",arr[k+1],arr[k],k);
					arr [k]=arr[k+1];
					k++;
					printf("%d-%d-%d\n",arr[k],arr[k-1],k);
				}while(k<size);
				printf("%d-%d-%d--\n",arr[k+1],arr[k],k);
				size--;j--;
			}
			j++;
		}while(j<size);
		i++;
	}while(i<size);
	i=0;do{printf("%d\t",arr[i]);i++;
	}while(i<size);



    return 0;
}
