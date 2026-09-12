//DOUBLY LINKED LIST
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

 void CreateNode(int value)  //create a linked list
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

void PrintList()  //print the linked list
{
    temp=head;
    printf("Linked List:");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


void InsertAtBeg()  //insert a data to the beginning
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

int getlength(){  //count the length of the linked list
    int count=0;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void InsertAtEnd()  //insert a data to the end
{

   struct Node*newnode;
   newnode=malloc(sizeof(struct Node));
   printf("Enter the data u want insert at the end:");
   scanf("%d",&newnode->data);
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

void InsertAtPos(){  //insert to the any position
    int pos,i=1;
    printf("enter the position u want to insert the data:");
    scanf("%d",&pos);
    if(pos>getlength()||pos<1){
        printf("Invalid position");
    }
    else if(pos==1)
            {
                InsertAtBeg();
                
            }
    else{
                struct Node*newnode;
                temp=head;
                newnode=malloc(sizeof(struct Node));
                printf("enter the value u want to insert at the pos:");
                scanf("%d",&newnode->data);
                newnode->next=NULL;
                newnode->prev=NULL;
                if(head==NULL)
                {
                    head=tail=newnode;
                }
                else{
                    while(i<pos-1){
                        temp=temp->next;
                        i++;
                    }
                    newnode->prev=temp;
                    newnode->next=temp->next;
                    temp->next=newnode;
                    newnode->next->prev=newnode;
                }
                 
    }

    }


void deleteatbeg(){  //delete from beginning
    if(head==NULL)
    {
        printf("list is empty");
    }
    else{
        temp=head;
        head=head->next;
        head->prev=0;
        free(temp);
    }
    
}

void deleteatend(){  //delete from end
    if(tail==NULL){
        printf("list is empty");
    }
    else{
        temp=tail;
        tail=tail->prev;
        tail->next=0;
        free(temp);
    }
    
}


void deleteatpos(){  //delete data from any position
    int pos,i=1;
    printf("enter the position u want to delete:");
    scanf("%d",&pos);
    if(pos>getlength()||pos<1){
        printf("invalid position");
    }
    else if(pos==1){
        deleteatbeg();
        
    }
    else if(pos==getlength()){
        deleteatend();
        
    }
    else{
        temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        
        
    

    }
}


void reverse(){  //reverse the linked list
    struct Node *current,*nextnode;
    if(head==NULL){
        printf("list is empty");
    }
    else{
        current=head;
        while(current!=0){
            nextnode=current->next;
            current->next=current->prev;
            current->prev=nextnode;
            current=nextnode;
        }
        current=head;
        head=tail;
        tail=current;
    }
    
}


 
int main(){
    int choice=1;
    int con=1;
    int choose;
    while(choice!=0)
    {
    int data;
    printf("enter the data:");
    scanf("%d",&data);
    CreateNode(data);
    printf("do you want to continue?(1/0):");
    scanf("%d",&choice);
    }
     while(con!=0)
 {
     printf("\n1.print the linked list");
     printf("\n2.insert the node at the beginning of the linked list");
     printf("\n3.insert the node at the end of the linked list");
     printf("\n4.insert the node at the given position of the linked list");
     printf("\n5.delete the node at the beginning of the linked list");
     printf("\n6.delete the node at the end of the linked list");
     printf("\n7.delete the node at the given position of the linked list");
     printf("\n8.reverse the linked list");
     printf("\n9.exit");
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
         deleteatbeg();
         PrintList();
         break;
     case 6:
         deleteatend();
         PrintList();
         break;
     case 7:
         deleteatpos();
         PrintList();
         break;
     case 8:
         reverse();
         PrintList();
         break;
     case 9:
         printf(" you are exit from the linked list");
         break;
     default:
         printf("invalid choose");
 } 
 printf("do you want to continue?(1/0):");
 scanf("%d",&con);
}  

 return 0;
}
    
 
    
     





    
    
    
    
 
 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
