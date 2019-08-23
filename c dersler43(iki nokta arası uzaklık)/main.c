#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int x[4];
    int y[4],in1,in2;
    int i,j;
    double uzaklik=0;
    for(i=0;i<4;i++)
    {
    printf("dizix'in %d. elemani:",i);
    scanf("%d",&x[i]);
    }
    for(i=0;i<4;i++)
    {
    printf("diziy'in %d. elemani:",i);
    scanf("%d",&y[i]);
    }
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<4;j++)
        {
            if(uzaklik<sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)))
            {
                uzaklik=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
                in1=i;
                in2=j;
            }
        }
    }
    printf("%.2lf      %d       %d",uzaklik,in1,in2);

    return 0;
}
