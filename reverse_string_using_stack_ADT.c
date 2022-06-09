
// C PROGRAM TO FIND REVERSE OF A STRING USING STACK ADT

#include<stdio.h>
#include<string.h>
char s[50];
int top=-1;
void push(char e)
{
    top++;
    s[top]=e;
}
void display()
{
    while(top>=0)
    {
        printf("%c",s[top]);
        top--;
    }
}
int main()
{
    char ch[50];
    printf("Enter string to be reversed: ");
    scanf("%s",ch);
    for(int i=0;i<strlen(ch);i++)
    push(ch[i]);
    printf("Reversed string: ");
    display();
}
