
// C PROGRAM TO IMPLEMENT HASHING TECHNIQUE

#include <stdio.h>
#include <conio.h>
#define HSIZE 7
void main()
{
    int key[10],H[HSIZE]={0,0,0,0,0,0,0},hash[10],hash1,i,j,n;
    printf("Enter no of elements:\n");
    scanf("%d",&n);
    printf("Enter Key values:\n");
    for(j=0;j<n;j++)
    {
        scanf("%d",&key[j]);
    }
    printf("output:\n");
    printf("Index\t\tHashtablevalue:\n");
    printf("------------------------:\n");
    for(j=0;j<n;j++)
    {
        hash[j]=key[j]%HSIZE;
        hash1=hash[j];
        printf("Index=%d\n",hash1);
        if(H[hash1]==0)
        {
            H[hash1]=key[j];
        }
        else
        {
            if(hash1==HSIZE-1)
            hash1=0;
            for(i=hash1;i<HSIZE;i++)
            {
                if(H[i]==0)
                {
                    H[i]=key[j];
                    break;
                }
            }
        }
    }
    for(i=0;i<HSIZE;i++)
    {
        printf("%d\t\t%d\n",i,H[i]);
    }
    getch();
}
