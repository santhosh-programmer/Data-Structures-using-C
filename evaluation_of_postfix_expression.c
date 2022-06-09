
// C PROGRAM FOR EVALUATION OF POSTFIX EXPRESSION

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int s[20],top=-1;
void push(int e)
{
    top++;
    s[top]=e;
}
int pop()
{
    int temp=top;
    top--;
    return s[temp];
}
int main()
{
    char str[20];
    int a,n,b,c;
    printf("Enter postfix expression: ");
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            printf("Enter value of %c: ",str[i]);
            scanf("%d",&n);
            push(n);
        }
        else
        {
            switch(str[i])
            {
                case '+':  a=pop()+pop();
                           push(a);
                           break;
                case '-':  b=pop();
                           c=pop();
                           a=c-b;
                           push(a);
                           break;
                case '*':  a=pop()*pop();
                           push(a);
                           break;
                case '/':  b=pop();
                           c=pop();
                           a=c/b;
                           push(a);
                           break;
            }
        }
    }
    printf("Solution: %d",pop());
    return 0;
}
