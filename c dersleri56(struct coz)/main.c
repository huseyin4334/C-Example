#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct course{

int course_id;
char course_code1[10];
char course_name[40];
char course_acronym[8];
int quota;

};
void generate_course_code(char *course_code,int course_id)
{
    if(course_id<10)
        sprintf(course_code,"CSE0%d",course_id);
    else
        sprintf(course_code,"CSE%d",course_id);
        printf("%s",course_code);

}
void generate_course_acronym(char *acronym,char *course_name)
{
   char tut[6];
   int k=1,i;

   tut[k-1]=toupper(course_name[0]);
   for(i=0;course_name[i]!='\0';i++)
   {
       if(course_name[i]==' ')
       {
            tut[k]=toupper(course_name[i+1]);
            k++;
       }
   }
   tut[k]='\0';
   k=1;
   sprintf(acronym,"<%s>",tut);
   printf("%s",acronym);
}

int main()
{
    int i;
    struct course courses[10];

    for(i=0;i<10;i++)
    {
        printf("enter course name:");
        gets(courses[i].course_name);
        printf("enter course quota:");
        scanf("%d",&courses[i].quota);
        while(getchar()!='\n');
        courses[i].course_id=i+1;
        generate_course_code(courses[i].course_code1,courses[i].course_id);
        generate_course_acronym(courses[i].course_acronym,courses[i].course_name);
    }
    for(i=0;i<10;i++)
    {
        printf("%-2d- %-2s - %-2s %-2s - %-2d\n",i+1,courses[i].course_code1,courses[i].course_name,courses[i].course_acronym,courses[i].quota);
    }
    return 0;
}
