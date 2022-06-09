
// C PROGRAM TO IMPLEMENT ARRAY IMPLEMENTATION OF QUEUE

#include<stdio.h>
int q[100],max,f=-1,r=-1;
int isfull()
{
    if(r==max-1)
    return 1;
    else
    return 0;
}
int isempty()
{
    if(r==-1)
    return 1;
    else
    return 0;
}
void enqueue(int e)
{
    if(isfull())
    printf("Queue overflow\n");
    else
    {
        r++;
        if(f==-1)
        f++;
        q[r]=e;
    }
}
void dequeue()
{
    if(isempty())
    printf("Queue underflow\n");
    else
    {
        printf("Deleted element: %d\n",q[f]);
        if(f==r)
        f=r=-1;
        else
        f++;
    }
}
void display()
{
    if(isempty())
    printf("Queue underflow");
    else
    {
        for(int i=f;i<=r;i++)
        printf("%d ",q[i]);
    }
    printf("\n");

}
int main()
{
    int e,n;
    printf("Enter maximum size: ");
    scanf("%d",&max);
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n)
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
    }while(n!=4);
    return 0;
}
