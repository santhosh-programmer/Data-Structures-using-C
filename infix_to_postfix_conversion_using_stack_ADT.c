
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
        case '/':return 2;
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
int main()
{
    char str[20];
    printf("Enter infix expression: ");
    scanf("%[^\n]s",str);
    printf("Postfix expresion: ");
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
        {
            if(top==-1)
            push(str[i]);
            else
            {
                if(pri(s[top])>=pri(str[i]))
                {
                    printf("%c",pop());
                    push(str[i]);
                }
                else
                push(str[i]);
            }
        }
        else if(str[i]=='(')
        push(str[i]);
        else if(str[i]==')')
        {
            while(s[top]!='(')
            printf("%c",pop());
            pop();
        }
        else if(str[i]>='a' && str[i]<='z')
        printf("%c",str[i]);
    }
    while(top>=0)
    printf("%c",pop());
    return 0;
}
