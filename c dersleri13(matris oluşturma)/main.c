#include <stdio.h>
#include <stdlib.h>

int main()
{
float matrix[100][100];
int i,j,line,column;
float total=0;
printf("Enter number of line of the matrix:");
scanf("%d",&line);
printf("Enter number of column of the matrix:");
scanf("%d",&column);
for(i=0;i<line;i++)
{
    for (j=0;j<column;j++)
    {
        printf("Enter %d.line and %d.column of the matrix:",i+1,j+1);

        scanf("%f",&matrix[i][j]);
    }
}
 for(i=0;i<line;i++)
{
    for (j=0;j<column;j++)
    {
        printf("%.1f ",matrix[i][j]);
    }
printf("\n");
}
for(i=0;i<line;i++)
{
    for (j=0;j<column;j++)
    {
        total+=matrix[i][j];
    }

}
printf("sum of elements of matrix:%.2f",total);
return 0;
}
