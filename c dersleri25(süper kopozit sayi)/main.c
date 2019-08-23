#include <stdio.h>
#include <stdlib.h>
int super_kompozit_sayi()
{
    int bolen,diger=0;
    int sayi1=1;
    int i,j,k;

    for (j=3000;j!=0;j--)
    {   sayi1=0;
        bolen=0;

        for(i=1;i<=j;i++)
        {
            if (j%i==0)
                bolen+=1;
        }



        for(i=j-1;i!=0;i--)
        {
            diger=0;
            for(k=1;k<=i;k++)
            {
                if (i%k==0)
                    diger+=1;

            }

            if(bolen>diger)
                sayi1+=1;

        }
        if (sayi1==j-1)
        {
            return j;
        }
    }

}






int main()
{
    int x;
   /* printf("Bir sayi giriniz : ");
    scanf("%d",&x);*/
    printf("%d",super_kompozit_sayi());

    return 0;
}
