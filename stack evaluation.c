#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct books{
    char book_name[20];
    struct books *next;
}*NODE;
NODE read_book(){
    NODE newbook=(NODE)malloc(sizeof(struct books));
    if(newbook==NULL)
        exit(0);
    scanf("%s",newbook->book_name);
    newbook->next=NULL;
    return newbook;

}
NODE push(NODE head){
    NODE newbook=read_book();
    if(head==NULL)
    {
        head=newbook;
        return head;
    }
    newbook->next=head;
    head=newbook;
    return head;
}
NODE head1=NULL;
NODE head2=NULL;
NODE head3=NULL;
void sort(NODE head){
    char s1[20]="Astronomic";
    char s2[20]="Physics";
    char s3[20]="Geography";
    NODE temp=head;
    NODE cur;
    while(temp!=NULL){
        if(strcmp(temp->book_name,s1)==0){
            if(head1==NULL){
                head1=temp;
                temp=temp->next;
                head1->next=NULL;
            }
            cur=temp->next;
            temp->next=head1;
            head1=temp;
            temp=cur;
        }
        else if(strcmp(temp->book_name,s2)==0){
            if(head1==NULL){
                head2=temp;
                temp=temp->next;
                head2->next=NULL;
            }
            cur=temp->next;
            temp->next=head1;
            head2=temp;
            temp=cur;
    }
    else{
            if(head1==NULL){
                head3=temp;
                temp=temp->next;
                head3->next=NULL;
            }
            cur=temp->next;
            temp->next=head1;
            head3=temp;
            temp=cur;
    }
        temp=temp->next;

}
}
void display(){
    NODE temp1=head1, temp2=head2, temp3=head3;
    int count1=0, count2=0, count3=0;
    while(temp1!=NULL){
        printf("%s",temp1->book_name);
        temp1=temp1->next;
        count1++;
    }
     while(temp2!=NULL){
        printf("%s",temp2->book_name);
        temp2=temp2->next;
        count2++;
    }
     while(temp3!=NULL){
        printf("%s",temp3->book_name);
        temp3=temp3->next;
        count3++;
    }
    printf("%d %d %d",count1,count2,count3);
}



int main() {

    NODE head;
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
    head=push(head);
    }
    sort(head);
    display();
    return 0;
}
