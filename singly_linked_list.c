
// C PROGRAM TO IMPLEMENT SINGLY LINKED LIST

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
    if (list->next==NULL)
    return 1;
    else
    return 0;
}
int islast(node *position)
{
    if(position->next==NULL)
    return 1;
    else
    return 0;
}
node *find(node *list,int e)
{
    node *position;
    if(isempty(list))
    {
        printf("List is empty\n");
    }
    else
    {
        position=list->next;
        while(position !=NULL && position->element !=e)
        {
            position=position->next;
        }
    }
    return position;
}
node *findnext(node *list,int e)
{
    node *position;
    position=find(list,e);
    return position->next;
}
node *findprevious(node *list,int e)
{
    node *position,*previous;
    position=list->next;
    previous=NULL;
    while(position !=NULL && position->element !=e)
    {
        previous=position;
        position=position->next;
    }
    return previous;
}
void print(node *list)
{
    if(isempty(list))
    {
        printf("List is empty");
    }
    else
    {
        node *position;
        position=list;
        while (position->next !=NULL)
        {
            position=position->next;
            printf("%d ",position->element);
        }
        printf("\n");
    }
}
void insertbeg(node *list,int e)
{
    node *newnode=(node *)malloc(sizeof(node));
    if(isempty(list))
    {
        newnode->next=NULL;
    }
    else
    {
        newnode->next=list->next;
    }
    list->next=newnode;
    newnode->element=e;
    printf("Element inserted\n");
}
void insertmiddle(node *list,int e,int p)
{
    node *position;
    position=findprevious(list,p);
    node *newnode=(node *)malloc(sizeof(node));
    newnode->element=e;
    newnode->next=position->next;
    position->next=newnode;
    printf("Element inserted\n");
}
void insertlast(node *list,int e)
{
    node *position;
    node *newnode=(node *)malloc(sizeof(node));
    newnode->element=e;
    newnode->next=NULL;
    if(isempty(list))
    {
        list->next=newnode;
    }
    else
    {
        position=list;
        while(position->next !=NULL)
        {
            position=position->next;
        }
        position->next=newnode;
    }
    printf("Element inserted\n");
}
void delbeg(node *list)
{
    if(isempty(list))
    {
        printf("List is empty");
    }
    else
    {
        node *tempnode;
        tempnode=list->next;
        list->next=tempnode->next;
        printf("Deleted element: %d\n",tempnode->element);
        free(tempnode);
    }
}
void delmiddle(node *list,int p)
{
    if(isempty(list))
    {
        printf("List is empty");
    }
    else
    {
        node *position;
        node *tempnode;
        position=findprevious(list,p);
        if(islast(position))
        {
            tempnode=position->next;
            position->next=NULL;
            printf("Deleted element: %d\n",tempnode->element);
            free(tempnode);
        }
        else
        {
            tempnode=position->next;
            position->next=tempnode->next;
            printf("The deleted item is %d\n",tempnode->element);
            free(tempnode);
        }
    }
}
void dellast(node *list)
{
    if(isempty(list))
    {
        printf("List is empty");
    }
    else
    {
        node *tempnode;
        node *position;
        position=list->next;
        while(position->next->next != NULL)
        {
            position=position->next;
        }
        tempnode=position->next;
        position->next=NULL;
        printf("The deleted element is %d\n",tempnode->element);
        free(tempnode);
    }
}
int main()
{
    node *list=(node *)malloc(sizeof(node));
    list->next=NULL;
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
                    insertmiddle(list,e,p);
                    break;
            case 3: printf("Enter element: ");
                    scanf("%d",&e);
                    insertlast(list,e);
                    break;
            case 4: delbeg(list);
                    break;
            case 5: printf("Enter position: ");
                    scanf("%d",&p);
                    delmiddle(list,p);
                    break;
            case 6: dellast(list);
                    break;
            case 7: printf("Enter element: ");
                    scanf("%d",&e);
                    if(find(list,e)!=NULL)
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