
// C PROGRAM FOR ADDITION OF TWO POLYNOMIALS

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
void insert(node *p,int c,int po)
{
    node *newnode=malloc(sizeof(node));
    newnode->next=NULL;
    newnode->pow=po;
    newnode->co=c;
    if(p->next==NULL)
    {
        p->next=newnode;
        position=newnode;
    }
    else
    {
        position->next=newnode;
        position=newnode;
    }
}
void display(node *ans)
{
    node *position=ans->next;
    printf("After addition: ");
    while(position!=NULL)
    {
        if(position->co!=0)
        {
            printf("%d",position->co);
            if(position->pow!=0)
            {
                printf("x^%d",position->pow);
                printf("+");    
            }
        }
        position=position->next;
    }
}
void add(node *poly1,node *poly2)
{
    node *ans=malloc(sizeof(node));
    ans->next=NULL;
    position=ans;
    node *p1=poly1->next;
    node *p2=poly2->next;
    while(p1!=NULL && p2!=NULL)
    {
        node *newnode=malloc(sizeof(node));
        newnode->next=NULL;
        if((p1->pow==p2->pow))
        {
            newnode->co=p1->co + p2->co;
            newnode->pow=p1->pow;
            p1=p1->next;
            p2=p2->next;
        }
        else if ((p1->pow > p2->pow))
        {
            newnode->co=p1->co;
            newnode->pow=p1->pow;
            p1=p1->next;
        }
        else if((p1->pow < p2->pow))
        {
            newnode->co=p2->co;
            newnode->pow=p2->pow;
            p2=p2->next;
        }
        position->next=newnode;
        position=newnode;
    }
    display(ans);
}

int main()
{
    int n,m;
    node *poly1=malloc(sizeof(node));
    node *poly2=malloc(sizeof(node));
    poly1->next=NULL;
    poly2->next=NULL;
    printf("Enter highest power of polynomial 1: ");
    scanf("%d",&n);
    printf("Enter coefficients (highest to lowest power): ");
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&m);
        insert(poly1,m,n-i);
    }
    printf("Enter highest power of polynomial 2: ");
    scanf("%d",&n);
    printf("Enter coefficients (highest to lowest power): ");
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&m);
        insert(poly2,m,n-i);
    }
    add(poly1,poly2);
    return 0;
}