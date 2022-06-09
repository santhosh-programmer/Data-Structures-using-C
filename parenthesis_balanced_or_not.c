
// C PROGRAM TO FIND WHETHER PARENTHESIS IS BALANCED OR NOT

#include<stdio.h>
#include<string.h>
int top=-1;
char s[100];
void push(char e)
{
    top++;
    s[top]=e;
}
int main()
{
    char ch[100];
    int flag;
    printf("Enter parenthesis: ");
    scanf("%s",ch);
    for(int i=0;i<strlen(ch);i++)
    push(ch[i]);
    for(int i=0,j=top;i<=top;i++,j--)
    {
        if(ch[i]==ch[j])
        {
            flag=1;
            printf("Not Balanced");
            break;
        }
    }
    if(flag!=1)
    printf("Balanced");
}