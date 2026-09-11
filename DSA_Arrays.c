
#include<stdio.h>

//Print the array
void traverse(int arr[], int*size)
{
    int i;
    for(i=0;i<*size;i++)
    {
        printf("%d index value is %d\n",i,arr[i]);
    }
}


//Search by value
int linearSearch(int arr[], int*size, int target)
{
    for(int i=0;i<*size;i++)
    {
        if(arr[i]==target)
        {
            return i;
        }

    }
    return -1;
}



//Assign the value to the given position
int updateByValue(int arr[], int*size,int oldValue, int newValue)
{
    int linearSearch_index=linearSearch(arr,&size,oldValue);

    if(linearSearch_index!=-1)
    {
        arr[linearSearch_index]=newValue;
        return 1;
    }
    return 0;
}



//Insertion
void insertAt(int arr[],int*size,int capacity,int position,int value)
{
    if(*size==capacity|| position>*size||position<0)
    {
        printf("cannot insert!");
    }
    else if(position==*size)
    {
        arr[*size]=value;
        printf("\nvalue is added at the %d index",*size);
        (*size)++;
        return;
    }
    else
    {
        for(int i=*size-1;i>=position;i--)
        {
            arr[i+1]==arr[i];
        }
        arr[position]=value;
         printf("\n value is added at the %d index",position);
        (*size)++;
        return;


    }
}




//Deletion
void deleteAt(int arr[],int*size,int position)
{
    if(*size==0||position>*size||position<0)
    {
        printf("cannot delete!");
    }
    else if(position>=*size)
    {

        printf("\nvalue is deleted at the %d index",*size);
        (*size)--;
        return;
    }
    else
    {
        for(int i=position;i<*size-1;i++)
        {
            arr[i]=arr[i+1];
        }

         printf("\n value is deleted at the %d index",position);
        (*size)--;
        return;


    }
}





int main()
{
    int arr[8]={10,20,30,40,50};
    int size=5;
    int value;
    int position;
    int capacity=8;
    //printf("enter the old value u want:");
   // scanf("%d",&old);
    //printf("enter the new value u want to insert:");
    //scanf("%d",&value);
    printf("enter the position u want to delete:");
    scanf("%d",&position);
    //int updateByValue_result= updateByValue(arr,&size,old,now);
   /* if(updateByValue_result)
    {
        printf("That value was updated\n");
    }
    else
    {
        printf("value is not updated");
    }*/

    traverse(arr,&size);
    printf("\n");
    deleteAt(arr,&size,position);
    traverse(arr,&size);
    return 0;


}
