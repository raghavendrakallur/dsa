#include<stdio.h>
#include<stdlib.h>

typedef struct matrix{
    int a[10][10];
    int m,n;
    struct matrix *next;
}*NODE;

NODE create_node()
{
    NODE newnode=(NODE)malloc(sizeof(struct matrix ));
    printf("enter the number of rows and columns :");
    scanf("%d %d",&newnode->m,&newnode->n);
    printf("enter the matrix ");
    for(int i=0; i<newnode->m; i++){
        for(int j=0; j<newnode->n; j++)
            scanf("%d",&newnode->a[i][j]);
    }
    newnode->next=NULL;
    return newnode;
}

NODE insert_front(NODE head){
    NODE newnode=create_node();
    if(head==NULL)
        head=newnode;
    NODE temp=newnode;
    newnode->next=head;
    head=temp;
    return head;
}

NODE insert_end(NODE head){
    NODE newnode=create_node();
    NODE temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
    return head;
}

NODE delete_front(NODE head){
    NODE temp=head;
    if(head==NULL)
    {
        printf("no list created ");
        return head;
    }
    head=head->next;
    free(temp);
    return head;
}

NODE delete_end(NODE head){
    NODE temp2=head, temp1;
    while(temp2->next!=NULL)
        temp2=temp2->next;
    while(temp1->next!=temp2)
        temp1=temp1->next;
    temp1->next=NULL;
    free(temp2);
    return head;
}

NODE display(NODE head){
    NODE temp=head;
    if(head==NULL)
    {
        printf("no list created ");
        return head;
    }
    while(temp->next!=NULL){
        for(int i=0; i<temp->m; i++){
            for(int j=0; j<temp->n; j++)
                printf("%d  ",temp->a[i][j]);
            printf("\n");
        }
        temp=temp->next;
    }
    return head;
}

void main(){
    int n;
    NODE head=NULL;
    while(1){
        printf("enter 1 to insert at front\n");
        printf("enter 2 to insert at the end\n");
        printf("enter 3 to delete from the front\n");
        printf("enter 4 to delete from the end\n");
        printf("enter 5 to display list\n");
        printf("enter 6 to exit\n");
        scanf("%d",&n);
        if(n==1)
            head=insert_front(head);
        else if(n==2)
            head=insert_end(head);
        else if(n==3)
            head=delete_front(head);
        else if(n==4)
            head=delete_end(head);
        else if(n==5)
            head=display(head);

        else
            return 0;

    }
}
