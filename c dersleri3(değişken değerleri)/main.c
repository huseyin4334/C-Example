#include <stdio.h>
#include <stdlib.h>
//alýþtýrma turlarý.
int main()
{
   char a1=66;
   char a2="hüseyin can kalcik";
   double a3=4.567;
   float a4=2.1;
   int a5=44;
   printf("%c\n%d\n%.3f\n%.1f\n%d\n",a1,a2,a3,a4,a5);
   printf("%d byte\n",sizeof(char));
   printf("%d byte\n",sizeof(int));
   printf("%d byte\n",sizeof(long int));
   printf("%d byte\n",sizeof(short int));
   printf("%d byte\n",sizeof(float));
   printf("%d byte\n",sizeof(double));
   return 0;
}
