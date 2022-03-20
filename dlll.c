//common operations on doubly linked list//
#include<stdio.h>
#include<stdlib.h>

typedef struct dll{
    int d;
    struct dll *pre,*next;
}*node;

node create_node()
{
    node newnode=(node)malloc(sizeof(struct dll));
    printf("enter the data: ");
    scanf("%d",&newnode->d);
    newnode->next=NULL;
    newnode->pre=NULL;
    return newnode;
}

node insert_front(node head){
    node newnode=create_node();
    if(head==NULL){
        head=newnode;
        return head;
    }
    newnode->next=head;
    head->pre=newnode;
    head=newnode;
    return head;
}

node insert_end(node head){
    node newnode=create_node();
    node temp=head;
    if(head==NULL){
        head=newnode;
        return head;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
    newnode->pre=temp;
    return head;
}

node insert_middle(node head){
    node newnode=create_node();
     if(head==NULL){
        head=newnode;
        return head;
    }
    node temp1=head;
    node temp2;
    int n;
    printf("enter the position of insertion\n");
    scanf("%d",&n);
    for(int i=1; i<n; i++){
        temp1=temp1->next;

    }
    temp2=temp1->pre;
    newnode->next=temp1;
    newnode->pre=temp2;
    temp2->next=newnode;
    temp1->pre=newnode;
    return head;

}

node display(node head){
    node temp=head;
    while(temp!=NULL){
        printf("%d   ",temp->d);
        temp=temp->next;
    }
    printf("\n");
    return head;
}

node delete_front(node head){
    node temp=head;
    head=head->next;
    temp->next=NULL;
    head->pre=NULL;
    free(temp);
    return head;
}

node delete_end(node head){
    node temp1=head;
    while(temp1->next!=NULL)
        temp1=temp1->next;
    node temp2=temp1->pre;
    temp2->next=NULL;
    temp1->pre=NULL;
    free(temp1);
    return head;
}

node delete_middle(node head){
    node temp1=head;
    int n;
    printf("enter the node number to be deleted :");
    scanf("%d",&n);
    for(int i=1; i<n; i++)
        temp1=temp1->next;
    node temp2=temp1->pre;
    node temp3=temp1->next;
    temp2->next=temp3;
    temp3->pre=temp2;
    temp1->next=NULL;
    temp1->pre=NULL;
    free(temp1);
    return head;
}

int main(){
    node head=NULL;
    int n;
    while(1){
        printf("enter 1 to insert front\n");
        printf("enter 2 to insert end\n");
        printf("enter 3 to insert at any position\n");
        printf("enter 4 to display the list\n");
        printf("enter 5 to delete form front\n");
        printf("enter 6 to delete form end\n");
        printf("enter 7 to delete form middle\n");
        printf("enter any other number to exit\n");
        scanf("%d",&n);
        if(n==1)
            head=insert_front(head);
        else if(n==2)
            head=insert_end(head);
        else if(n==3)
            head=insert_middle(head);
        else if(n==4)
            head=display(head);
        else if(n==5)
            head=delete_front(head);
         else if(n==6)
            head=delete_end(head);
        else if(n==7)
            head=delete_middle(head);
        else
            return 0;
    }

}
