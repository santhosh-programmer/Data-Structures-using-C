
//  C PROGRAM FOR ARRAY IMPLEMENTATION OF CIRCULAR QUEUE

#include<stdio.h>
#define max 5
int q[max],f=-1,r=-1;
int isfull()
{
    if(f==(r+1)%max)
    return 1;
    else
    return 0;
}
int isempty()
{
    if(f==-1)
    return 1;
    else
    return 0;
}
void enqueue(int e)
{
    if(isfull())
    printf("Queue Overflow\n");
    else
    {
        r=(r+1)%max;
        q[r]=e;
        if(f==-1)
        f=r;
    }
}
void dequeue()
{
    if(isempty())
    printf("Queue Underflow\n");
    else
    {
        printf("Deleted element: %d\n",q[f]);
        if(f==r)
        f=r=-1;
        else
        f=(f+1)%max;
    }
}
void display()
{
    if(isempty())
    printf("Queue Underflow\n");
    else
    {
        int i;
        for(i=f;i!=r;i=(i+1)%max)
        printf("%d ",q[i]);
        printf("%d\n",q[i]);
    }
}
int main()
{
    int e,ch;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    do
    {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element: ");
                    scanf("%d",&e);
                    enqueue(e);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exited");
                    break;
            default:printf("Invalid");
        }
    }while(ch!=4);
    return 0;
}
