
// C PROGRAM FOR LINKED LIST IMPLEMENTATION OF QUEUE

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int element;
    struct node *next;
}*front=NULL,*rear=NULL;
typedef struct node node;
int isempty()
{
    if(front==NULL)
    return 1;
    else
    return 0;
}
void enqueue(int e)
{
    node *newnode=malloc(sizeof(node));
    newnode->element=e;
    newnode->next=NULL;
    if(isempty())
    front=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue()
{
    if(isempty())
    printf("Queue Underflow\n");
    else
    {
        node *tempnode=front;
        printf("Deleted element: %d\n",tempnode->element);
        if(front==rear)
        front=rear=NULL;
        else
        front=front->next;
        free(tempnode);
    }
}
void display()
{
    if(isempty())
    printf("Queue Underflow\n");
    else
    {
        node *position=front;
        while(position!=NULL)
        {
            printf("%d ",position->element);
            position=position->next;
        }
        printf("\n");
    }
}
int main()
{
    int ch,e;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.exit\n");
    do
    {
        printf("Enter your choice: ");
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
            default:printf("Invalid\n");
        }
    }while (ch!=4);
    return 0;
}