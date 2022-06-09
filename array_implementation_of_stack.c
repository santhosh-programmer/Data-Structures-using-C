
// C PROGRAM TO IMPLEMENT ARRAY IMPLEMENTATION OF STACK

#include<stdio.h>
#define max 5
int s[max],top=-1;
int isfull()
{
    if (top==max-1)
    return 1;
    else
    return 0;
}
int isempty()
{
    if (top==-1)
    return 1;
    else
    return 0;
}
void push(int e)
{
    if(isfull())
    printf("Stack Overflow\n");
    else
    {
        top++;
        s[top]=e;
    }
}
void pop()
{
    if(isempty())
    printf("Stack Underflow\n");
    else
    {
        printf("Deleted element: %d\n",s[top]);
        top--;
    }
}
void peak()
{
    if(isempty())
    printf("Stack Underflow\n");
    else
    printf("Peak: %d\n",s[top]);
}
void print()
{
    if(isempty())
    printf("Stack Underflow");
    else
    {
        for(int i=top;i>-1;i--)
        printf("%d ",s[i]);
    }
    printf("\n");
}
int main()
{
    int n,m;
    printf("1.push\n2.pop\n3.peak\n4.print\n5.exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: printf("Enter element: ");
                    scanf("%d",&m);
                    push(m);
                    break;
            case 2: pop();
                    break;
            case 3: peak();
                    break;
            case 4: print();
                    break;
            case 5: printf("Exited");
                    break;
            default:printf("Invalid\n");
        }
    }while (n!=5);
    return 0;
}