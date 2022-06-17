
// C PROGRAM FOR INFIX TO POSTFIX CONVERSION USING STACK ADT

#include<stdio.h>
#include<string.h>
char s[20];
int top=-1;
int pri(char c)
{
    switch(c)
    {
        case '+':
        case '-':return 1;
                 break;
        case '*':
        case '%':
        case '/':return 2;
                 break;
        case '^':return 3;
                 break;
        default: return 0;
    }
}
void push(char c)
{
    top++;
    s[top]=c;
}
char pop()
{
    int a=top;
    top--;
    return s[a];
}
void convert(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/' ||ch=='^')
        {
            if(top==-1)
            push(ch);
            else
            {
                if(pri(s[top])>=pri(ch))
                {
                    printf("%c",pop());
                    convert(ch);
                }
                else
                push(ch);
            }
        }
        else if(ch=='(')
        push(ch);
        else if(ch==')')
        {
            while(ch!='(')
            printf("%c",pop());
            pop();
        }
        else if(ch>='a' && ch<='z')
        printf("%c",ch);
}
int main()
{
    char str[20];
    printf("Enter infix expression: ");
    scanf("%[^\n]s",str);
    printf("Postfix expresion: ");
    for(int i=0;i<strlen(str);i++)
    convert(str[i]);
    while(top>=0)
    printf("%c",pop());
    return 0;
}
