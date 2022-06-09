
// C PROGRAM FOR LINKED LIST IMPLEMENTATION OF STACK

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int element;
    struct node *next;
}*stack=NULL;
typedef struct node node;
int isempty()
{
    if(stack==NULL)
    return 1;
    else
    return 0;
}
void push(int e)
{
    node *newnode=malloc(sizeof(node));
    newnode->element=e;
    if(isempty())
    {
        newnode->next=NULL;
        stack=newnode;
    }
    else
    {
        newnode->next=stack;
        stack=newnode;
    }
}
void pop()
{
    if(isempty())
    printf("Stack Underflow\n");
    else
    {
        node *tempnode=stack;
        stack=stack->next;
        printf("Deleted element: %d\n",tempnode->element);
        free(tempnode);
    }
}
void top()
{
    if(isempty())
    printf("Stack Underflow\n");
    else
    printf("Top: %d\n",stack->element);
}
void display()
{
    if(isempty())
    printf("Stack Underflow\n");
    else
    {
        node *position=stack;
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
    printf("1.push\n2.pop\n3.peak\n4.print\n5.exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element: ");
                    scanf("%d",&e);
                    push(e);
                    break;
            case 2: pop();
                    break;
            case 3: top();
                    break;
            case 4: display();
                    break;
            case 5: printf("Exited");
                    break;
            default:printf("Invalid\n");
        }
    }while (ch!=5);
    return 0;
}