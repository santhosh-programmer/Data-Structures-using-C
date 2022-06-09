
// C PROGRAM TO IMPLEMENT SIMPLE ARRAY IMPLEMENTATION OF LIST

#include<stdio.h>
int n=0,i;
void insert(int arr[],int e,int p)
{
    for (i=n-1;i>=p;i--)
    arr[i+1]=arr[i];
    arr[p]=e;
    n+=1;
    printf("No of elements after inserting: %d",n);
}
void delete(int arr[],int p)
{
    for (i=p;i<n;i++)
    arr[i]=arr[i+1];
    n-=1;
    printf("No of elements after deletion: %d",n);
}
void print(int arr[])
{
    printf("list: ");
    for (i=0;i<n;i++)
    printf("%d ",arr[i]);
}
void search(int arr[],int e)
{
    int a=0;
    for (i=0;i<n;i++)
    {
        if(arr[i]==e)
        {
            printf("Element is found in %dth index",i);
            a++;
            break;
        }
    }
    if(a==0)
    printf("Element not found");
}
void sort(int arr[],int e)
{
    int temp;
    printf("Sorted list: ");
    for (i=0;i<n;i++)
    {   int j;
        if(e==1)
        j=i+1;
        if(e==2)
        j=0;
        for (j;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for (i=0;i<n;i++)
    printf("%d ",arr[i]);
}
int main()
{
    int ch,p,e;
    int arr[100];
    printf("1.Insert\n2.Delete\n3.Print\n4.Search\n5.Sort\n6.Exit");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element to be inserted: ");
                    scanf("%d",&e);
                    printf("Enter position: ");
                    scanf("%d",&p);
                    insert(arr,e,p);
                    break;
            case 2: printf("Enter position of the element: ");
                    scanf("%d",&p);
                    delete(arr,p);
                    break;
            case 3: print(arr);
                    break;
            case 4: printf("Enter element to be searched: ");
                    scanf("%d",&e);
                    search(arr,e);
                    break;
            case 5: printf("Enter 1 for ascending order, 2 for desending order: ");
                    scanf("%d",&e);
                    sort(arr,e);
                    break;
            case 6:printf("Exited");
                   break;
            default:printf("Invalid");
        }
    }while(ch!=6);
    return 0;
}