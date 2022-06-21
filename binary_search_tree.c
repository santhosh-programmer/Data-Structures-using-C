
// C PROGRAM TO IMPLEMENT BINARY SEARCH TREE

#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>
struct node 
{
    int element;
    struct node *right;
    struct node *left;
};
typedef struct node node;
node *tree=NULL;
node *insert(node *tree,int e)
{
    if(tree==NULL)
    {
        node *newnode=malloc(sizeof(node));
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->element=e;
        tree=newnode;
    }
    else if(e<tree->element)
    tree->left=insert(tree->left,e);
    else if(e>tree->element)
    tree->right=insert(tree->right,e);
    return  tree;
}
node *inorder(node *tree)
{
    if(tree==NULL)
    return tree;
    else
    {
        inorder(tree->left);
        printf("%d ",tree->element);
        inorder(tree->right);
    }
}
node *preorder(node *tree)
{
    if(tree==NULL)
    return tree;
    else
    {
        printf("%d ",tree->element);
        preorder(tree->left);
        preorder(tree->right);
    }
}
node *postorder(node *tree)
{
    if(tree==NULL)
    return tree;
    else
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ",tree->element);
    }
}
void find(node *tree,int e)
{
    if(tree==NULL)
    printf("Element not found\n");
    else if(e<tree->element)
    find(tree->left,e);
    else if(e>tree->element)
    find(tree->right,e);
    else
    printf("Element found\n");
}
node *findmin(node *tree)
{
    if(tree!=NULL)
    {
        if(tree->left==NULL)
        return tree;
        else
        tree=findmin(tree->left);
    }
    return tree;
}
node *findmax(node *tree)
{
    if(tree==NULL)
    return NULL;
    else if(tree->right==NULL)
    return tree;
    else
    findmax(tree->right);
}
node *delete(node *tree,int e)
{
    
    if(e<tree->element)
    tree->left=delete(tree->left,e);
    else if(e>tree->element)
    tree->right=delete(tree->right,e);
    else
    {
        if(tree->left==NULL && tree->right==NULL)
        {
            printf("Deleted element: %d\n",tree->element);
            tree=NULL;
            free(tree);
            return NULL;
        }
        else if(tree->left==NULL)
        {
            printf("Deleted element: %d\n",tree->element);
            free(tree);
            return NULL;
        }
        else if(tree->right==NULL)
        {
            printf("Deleted element: %d\n",tree->element);
            free(tree);
            return NULL;
        }
        else
        {
            node *tempnode=findmin(tree->right);
            tree->element=tempnode->element;
            tree->right=delete(tree->right,tempnode->element);
            return tree;
        }
    }
}
int main()
{
    int e,ch;
    node *temp=NULL;
    int arr[]={5,4,6,3,7,2,8};
    printf("1.insert\n2.delete\n3.find\n4.inorder\n5.preorder\n6.postorder\n7.find min\n8.find max\n9.exit\n");
    do
    {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: for(int i=0;i<7;i++)
                    {
                        tree=insert(tree,arr[i]);
                    }
                    break;
            case 2: printf("Enter element: ");
                    scanf("%d",&e);
                    delete(tree,e);
                    break;
            case 3: printf("Enter element: ");
                    scanf("%d",&e);
                    find(tree,e);
                    break;
            case 4: inorder(tree);
                    printf("\n");
                    break;
            case 5: preorder(tree);
                    printf("\n");
                    break;
            case 6: postorder(tree);
                    printf("\n");
                    break;
            case 7: temp=findmin(tree);
                    if(temp==NULL)
                    printf("Tree is empty\n");
                    else
                    printf("Minimum: %d\n",temp->element);
                    break;
            case 8: temp=findmax(tree);
                    if(temp==NULL)
                    printf("Tree is empty\n");
                    else
                    printf("Maximum: %d\n",temp->element);
                    break;
            case 9: printf("Exited");
                    break;
            default:printf("Invalid");
        }
    }while(ch!=9);
    return 0;
}