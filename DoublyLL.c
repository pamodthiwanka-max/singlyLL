#include<stdio.h>
#include<stdlib.h>
  struct Node
 {
     int data;
     struct Node*next;
     struct Node*prev;
 };
 struct Node*head=NULL;
 struct Node*tail=NULL;
 struct Node*temp=NULL;
 int count=0;
 void CreateNode(int value)
 {
     struct Node*newnode;
     newnode=malloc(sizeof(struct Node));
     newnode->data=value;
     newnode->next=NULL;
     newnode->prev=NULL;
     if(head==NULL)
     {
         head=tail=newnode;
     }
     else
     {
         tail->next=newnode;
         newnode->prev=tail;
         tail=newnode;
     }
 }
void PrintList()
{
    temp=head;
    printf("Linked List:");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\n");
    
}
void InsertAtBeg()
{
    struct Node*newnode;
    newnode=malloc(sizeof(struct Node));
    printf("Enter the data u want insert at the beginning:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=tail=newnode;
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
    PrintList();
}

int main(){
    int choice=1;
    while(choice!=0)
    {
    int data;
    printf("enter the data:");
    scanf("%d",&data);
    CreateNode(data);
    printf("do you want to continue?(1/0):");
    scanf("%d",&choice);
    }
    PrintList();
    InsertAtBeg();

    return 0;


}
