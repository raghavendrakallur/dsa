#include <stdio.h>
#include <stdlib.h>

typedef struct dll
{
    int n;
    struct dll *next;
    struct dll *bot;
}  *node;
 node insert_next(node head);
node getnode ();
 node insert_bot(node head);
 void display(node head);
 void sort(node head);


int main()
{
    int choice;
   node head =NULL;
   while(1)
   {
       printf("enter choiec\n");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
        head=insert_next(head);
        break;
       case 2:
        head=insert_bot(head);
        break;
        case 3:
        display(head);
        break;
         case 4:
        sort(head);
        break;
        case 5:
        exit(0);
        break;
        default:
            printf("invalid option \n");
       }
   }
    return 0;
}

node getnode ()
 {
     node new1;
     new1=(node) malloc(sizeof (struct dll));
     new1->next=NULL;
     new1->bot=NULL;
     printf("enter n\n");
     scanf("%d",&new1->n);
     return new1;
 }
 node getnode2 ()
 {
     node new1;
     new1=(node) malloc(sizeof (struct dll));
     new1->next=NULL;
     new1->bot=NULL;
     return new1;
 }
 node insert_next(node head)
 {
     node cur=head;
     node new1=getnode();
     if(head==NULL)
     return new1;
     while(cur->next!=NULL)
     {
         cur=cur->next;
     }
     cur->next=new1;
     new1->next=NULL;
     return head;
 }
 node insert_bot(node head)
 {
     node cur=head;
     while(cur->next!=NULL)
        cur=cur->next;
        while(cur->bot!=NULL)
            cur=cur->bot;
     node new1=getnode();
     cur->bot=new1;
     return head;
 }
 void display(node head)
{
    node cur=head;
    if(head==NULL)
    printf("list is empty\n");
    else
    {
        printf("your data in the list is:\n ");
        while(cur!=NULL)
        {
            printf("%d--",cur->n);
            node b=cur;
            b=b->bot;
            while(b!=NULL)
            {
             printf("%d --",b->n);
             b=b->bot;
            }
            printf("\nv");
            printf("\n");
            cur=cur->next;
        }
    }
}
 void sort(node head)
 {
     node cur=head;
     node tali=getnode2();
     tali->next=NULL;
     node naya=tali;
       while(cur!=NULL)
        {
            naya->n=cur->n;
            node b=cur;
            b=b->bot;
            node new1=getnode2();
            new1->next=NULL;
            naya->next=new1;
            naya=new1;
            while(b!=NULL)
            {
             naya->n=b->n;
             node new2=getnode2();
             new2->next=NULL;
            naya->next=new2;
            naya=new2;
             b=b->bot;
            }
            cur=cur->next;
        }
        cur=tali;
        printf("sorted list is:\n ");
        while(cur->next!=NULL)
        {
            printf("%d \n",cur->n);
            cur=cur->next;
        }


 }
