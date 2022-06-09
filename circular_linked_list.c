
// C PROGRAM TO IMPLEMENT CIRCULAR LINKED LIST

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int element;
    struct node *next;
};
typedef struct node node;
int isempty(node *list)
{
    if(list->next==list)
    return 1;
    else
    return 0;
}
int islast(node *list,node *position)
{
    if(position->next==list)
    return 1;
    else
    return 0;
}
node *find(node *list,int e)
{
    node *position=list->next;
    while(position!=list &&position->element!=e)
    position=position->next;
    return position;
}
node *findprev(node *list,int e)
{
    node *position=list->next;
    while(position->next->element!=e)
    position=position->next;
    return position;
}
node *findnext(node *list,int e)
{
    node *position=find(list,e);
    return position->next;
}
void insertbeg(node *list,int e)
{
    node *newnode=malloc(sizeof(node));
    newnode->element=e;
    if (isempty(list))
    {
        newnode->next=list;
        list->next=newnode;
    }
    else
    {
        newnode->next=list->next;
        list->next=newnode;
    }
}
void insertmid(node *list,int e,int p)
{
    if(isempty(list))
    insertbeg(list,e);
    else
    {
        node *newnode=malloc(sizeof(node));
        newnode->element=e;
        node *position=findprev(list,p);
        newnode->next=position->next;
        position->next=newnode;
    }
}
void insertlast(node *list,int e)
{
    if(isempty(list))
    insertbeg(list,e);
    else
    {
        node *newnode=malloc(sizeof(node));
        newnode->element=e;
        node *position=list->next;
        while(position->next!=list)
        position=position->next;
        position->next=newnode;
        newnode->next=list;
    }
}
void delbeg(node *list)
{
    if(isempty(list))
    printf("List is empty\n");
    else
    {
        node *tempnode=list->next;
        list->next=tempnode->next;
        printf("Deleted element:%d\n",tempnode->element);
        free(tempnode);
    }
}
void delmid(node *list,int p)
{
    if(isempty(list))
    printf("List is empty\n");
    else
    {
        node *position=findprev(list,p);
        node *tempnode=position->next;
        position->next=tempnode->next;
        printf("Deleted element:%d\n",tempnode->element);
        free(tempnode);
    }
}
void dellast(node *list)
{
    if(isempty(list))
    printf("List is empty\n");
    else
    {
        node *position=list->next;
        while(position->next->next!=list)
        position=position->next;
        node *tempnode=position->next;
        position->next=list;
        printf("Deleted element: %d\n",tempnode->element);
        free(tempnode);
    }
}
void print(node *list)
{
    if(isempty(list))
    printf("List is empty\n");
    else
    {
        node *position=list->next;
        while(position!=list)
        {
            printf("%d ",position->element);
            position=position->next;
        }
        printf("\n");
    }
}
int main()
{
    node *list=malloc(sizeof(node));
    list->next=list;
    int e,p,n;
    printf("\n1.Insert beginning\n2.Insert middle\n3.Insert last\n4.Delete beginning\n5.Delete middle\n6.Delete last\n7.Find\n8.Print\n9.Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: printf("Enter element: ");
                    scanf("%d",&e);
                    insertbeg(list,e);
                    break;
            case 2: printf("Enter element: ");
                    scanf("%d",&e);
                    printf("Enter position: ");
                    scanf("%d",&p);
                    insertmid(list,e,p);
                    break;
            case 3: printf("Enter element: ");
                    scanf("%d",&e);
                    insertlast(list,e);
                    break;
            case 4: delbeg(list);
                    break;
            case 5: printf("Enter position: ");
                    scanf("%d",&p);
                    delmid(list,p);
                    break;
            case 6: dellast(list);
                    break;
            case 7: printf("Enter element: ");
                    scanf("%d",&e);
                    if(find(list,e)!=list)
                    printf("Element is found\n");
                    else
                    printf("Element not found\n");
                    break;
            case 8: print(list);
                    break;
            case 9: printf("Exited");
                    break;
            default:printf("Invalid\n");
        }
    }while(n!=9);
    return 0;
}