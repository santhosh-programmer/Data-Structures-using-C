
// C PROGRAM TO IMPLEMENT DOUBLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int element;
    struct node *next;
    struct node *pre;
};
typedef struct node node;
int isempty(node *list)
{
    if(list->next==NULL)
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
void print(node *list)
{
    if(isempty(list))
    printf("List is empty\n");
    else
    {
        node *position;
        position=list;
        while(position->next!=NULL)
        {
            position=position->next;
            printf("%d ",position->element);
        }
        printf("\n");
    }
}
node *find(node *list,int p)
{
    node *position;
    if(isempty(list))
    {
        printf("List is empty\n");
        return NULL;
    }
    else
    {
        position=list->next;
        while(position !=NULL && position->element !=p)
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
    node *position;
    position=find(list,e);
    return position->pre;
}
void insertbeg(node *list,int e)
{
    node *newnode=malloc(sizeof(node));
    newnode->element=e;
    if(isempty(list))
    {
        list->next=newnode;
        newnode->pre=list;
        newnode->next=NULL;
        printf("Element inserted\n");
    }
    else
    {
        newnode->pre=list;
        newnode->next=list->next;
        list->next->pre=newnode;
        list->next=newnode;
        printf("Element inserted\n");
    }
}
void insertmid(node *list,int e,int p)
{
    node *newnode=malloc(sizeof(node));
    newnode->element=e;
    node *position;
    position=find(list,p);
    /*if(isempty(list))
    {
        newnode->next=NULL;
        newnode->pre=list;
        list->next=newnode;
        printf("Element inserted\n");
    }
    else
    {*/
        if(islast(position))
        {
            position->next=newnode;
            newnode->pre=position;
            newnode->next=NULL;
            printf("Element inserted\n");
        }
        else
        {
            newnode->pre=position->pre;
            newnode->next=position;
            position->pre->next=newnode;
            position->pre=newnode;
            printf("Element inserted\n");
        }
    //}
}
void insertlast(node *list,int e)
{
    node *newnode=malloc(sizeof(node));
    newnode->element=e;
    if(isempty(list))
    {
        list->next=newnode;
        newnode->pre=list;
        newnode->next=NULL;
        printf("Element inserted\n");
    }
    else
    {
        node *position;
        position=list->next;
        while(position->next!=NULL)
        {
            position=position->next;
        }
        position->next=newnode;
        newnode->pre=position;
        newnode->next=NULL;
        printf("Element inserted\n");
    }
}
void delbeg(node *list)
{
    if(isempty(list))
    {
        printf("List is empty\n");
    }
    else
    {
        node *tempnode;
        tempnode=list->next;
        if(islast(tempnode))
        {
            tempnode->pre->next=NULL;
            printf("Deleted element: %d\n",tempnode->element);
            free(tempnode);  
        }
        else
        {
            list->next=tempnode->next;
            tempnode->next->pre=list;
            printf("Deleted element: %d\n",tempnode->element);
            free(tempnode);
        }
    }
}
void delmid(node *list,int p)
{
    if(isempty(list))
    {
        printf("List is empty\n");
    }
    else
    {
        node *position;
        position=find(list,p);
        node *tempnode;
        tempnode=position;
        if(islast(position))
        {
            tempnode->pre->next=NULL;
            printf("Deleted element: %d\n",tempnode->element);
            free(tempnode);
        }
        else
        {
            tempnode->pre->next=tempnode->next;
            tempnode->next->pre=tempnode->pre;
            printf("Deleted element: %d\n",tempnode->element);
            free(tempnode);
        }
    }
}
void dellast(node *list)
{
    if(isempty(list))
    {
        printf("List is empty\n");
    }
    else
    {
        node *position;
        position=list->next;
        while(position->next!=NULL)
        {
            position=position->next;
        }
        node *tempnode;
        tempnode=position;
        tempnode->pre->next=NULL;
        printf("Deleted element: %d\n",tempnode->element);
        free(tempnode);
    }
}
int main()
{
    node *list=malloc(sizeof(node));
    list->next=NULL;
    list->pre=NULL;
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