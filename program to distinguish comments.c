/* c program to distinguish comments*/
#include<stdio.h>
main()
{
int no,i=1;
char c;
printf("enter the number of comments:");
scanf("%d",no);
while(i<=no)
{
   printf("enter the comment:");
   scanf("%c",&c);
   switch(c)
   {
   case'p': printf("1");
          break;
   case'n': printf("2");
         break;
   case'd': printf("3");
   }
i++;
}
}
