
// C PROGRAM FOR POLYNOMIAL DIFFERENTIATION

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int pow;
    int co;
    struct node *next;
};
typedef struct node node;
node *position;
void diff(node *ans,int c,int p)
{
    node *newnode=malloc(sizeof(node));
    newnode->next=NULL;
    if(p>0)
    {
        newnode->pow=p-1;
        newnode->co=p*c;
        if(ans->next==NULL)
        {  
            ans->next=newnode;
            position=newnode;
        }
        else
        {
            position->next=newnode;
            position=newnode;
        }
    }
}
void display(node *ans)
{
    node *position=ans->next;
    while(position!=NULL)
    {
        if(position->co!=0)
        {
            printf("%dx^%d ",position->co,position->pow);
            if(position->pow!=0 && position->co>0)
            printf("+ ");
        }
        position=position->next;
    }
}
int main()
{
    int n,m;
    node *ans=malloc(sizeof(node));
    ans->next=NULL;
    printf("Enter highest power: ");
    scanf("%d",&n);
    printf("Enter coefficients(from highest power to lowest power): ");
    for(int i=0;i<n;i++)
    {
        scanf("%d ",&m);
        diff(ans,m,n-i);
    }
    printf("Differentiated polynomial: ");
    display(ans);
    return 0;
}