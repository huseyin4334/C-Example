#include <stdio.h>
#include <stdlib.h>
#include<math.h>
//dudeney sayi
int main()
{
    int i;
    int toplam=0;
    int kup;
    for(i=1;pow(i,3)<30000;i++)
    {
        kup=pow(i,3);
        while(kup!=0)
        {
            toplam+=kup%10;
            kup=kup/10;
        }
        if(i==toplam)
            printf("%1.f bir dudeney sayidir.\n",pow(i,3));
        toplam=0;



    }
    return 0;
}
