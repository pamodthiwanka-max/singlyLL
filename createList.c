#include<stdio.h>
#include<stdlib.h>
  struct Node
 {
     int data;
     struct Node*next;

 };
 struct Node*head=NULL;
 struct Node*tail=NULL;
 struct Node*temp=NULL;
 int count=0;
void CreateNode(int value){

    struct Node*newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=temp=newNode;
    }
    else
    {
        temp->next=newNode;
        temp=newNode;
    }

}
// print the linked list
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
    printf("%d\n",count);
}
//insert the node at the beginning of the linked list
void InsertAtBeg()
{
    struct Node*newNode;
    newNode=malloc(sizeof(struct Node));
    printf("Enter the data u want to insert at beginning:");
    scanf("%d",&newNode->data);
    newNode->next=head;
    head=newNode;
}

// insert the node at the end of the linked list
void InsertAtEnd()
{
    struct Node*newNode;
    newNode=malloc(sizeof(struct Node));
    printf("Enter the data u want to insert at end:");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

//insert the node at the given position of the linked list
void InsertAtPos()
{
    int pos,i=1;
    printf("enter the position do u want to insert a value:");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("invalid position");
    }
    else if(pos==1)
    {
        InsertAtBeg();
    }
    else if(pos==count+1)
    {
        InsertAtEnd();
    }
    else
    {
        struct Node*newNode;
    newNode=malloc(sizeof(struct Node));
    printf("Enter the data u want to insert at the position:");
    scanf("%d",&newNode->data);
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}



// delete the node at the end of the linked list
void DeleteAtBeg()
{
    if(head==NULL)
    {
        printf("No data");
    }
    else
    {
    temp=head;
    head=temp->next;
    free(temp);
    }
}



// delete the node at the end of the linked list
void DeleteAtEnd()
{
    struct Node*prevNode;
    temp=head;
    while(temp->next!=NULL)
    {
        prevNode=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=0;
        free(temp);
    }
    else
    {
        prevNode->next=NULL;
        free(temp);
    }
}

//delete the node at the given position of the linked list
void DeleteAtPos()
{
    int pos,i=1;
    struct Node*nextNode;
    temp=head;
    printf("enter position u want to delete:");
    scanf("%d",&pos);
     if(pos>count)
    {
        printf("invalid position");
    }
    else if(pos==1)
    {
        DeleteAtBeg();
    }
    else if(pos==count)
    {
        DeleteAtEnd();
    }
    else{
     while(i<pos-1)
     {
        temp=temp->next;
        i++;
     }
    }
    nextNode=temp->next;
    temp->next=nextNode->next;
    free(nextNode);
}
void Reversed()
{
    struct Node*prevNode,*nextNode,*currentNode;
    prevNode=0;
    currentNode=nextNode=head;
    while(nextNode!=NULL)
    {
        nextNode=nextNode->next;
        currentNode->next=prevNode;
        prevNode=currentNode;
        currentNode=nextNode;
    }
    head=prevNode;
}

//main function
int main(){
    int choice=1;
    int choose;
    int con;
    while(choice!=0)
    {
    int data;
    int count=0;
    printf("enter the data:");
    scanf("%d",&data);
    CreateNode(data);
    printf("do you want to continue?(1/0):");
    scanf("%d",&choice);
    }

    
    while(choose!=0)
    {
        printf("\n1.print the linked list");
        printf("\n2.insert the node at the beginning of the linked list");
        printf("\n3.insert the node at the end of the linked list");
        printf("\n4.insert the node at the given position of the linked list");
        printf("\n5.delete the node at the beginning of the linked list");
        printf("\n6.delete the node at the end of the linked list");
        printf("\n7.delete the node at the given position of the linked list");
        printf("\n8.reverse the linked list");
        printf("\nenter your choose:");
        scanf("%d",&choose);
    
    switch(choose)
    {
        case 1:
            PrintList();
            break;
        case 2:
            InsertAtBeg();
            PrintList();
            break;
        case 3:
            InsertAtEnd();
            PrintList();
            break;
        case 4:
            InsertAtPos();
            PrintList();
            break;
        case 5:
            DeleteAtBeg();
            PrintList();
            break;
        case 6:
            DeleteAtEnd();
            PrintList();
            break;
        case 7:
            DeleteAtPos();
            PrintList();
            break;
        case 8:
            Reversed();
            PrintList();
            break;
        default:
            printf("invalid choose");
    } 
    printf("do you want to continue?(1/0):");
    scanf("%d",&con);

}  
    return 0;


}
