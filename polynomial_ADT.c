
// C PROGRAM TO IMPLEMENT POLYNOMIAL ADT-ADDITION,SUBTRACTION,DIFFERENTIATION OF POLYNOMIALS

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int pow;
    struct node *next;
};
typedef struct node Poly;
void Create(Poly *List)
{
    int choice;
    Poly *newnode,*Position;
    Position=List;
    do
    {
       newnode=(Poly*)malloc(sizeof(Poly));
       printf("Enter the coefficient: ");
       scanf("%d",&newnode->coeff);
       printf("Enter the power: ");
       scanf("%d",&newnode->pow);
       newnode->next=NULL;
       Position->next=newnode;
       Position=newnode;
       printf("Press 1 to continue\n");
       scanf("%d",&choice);
    }while(choice==1);
}
void Display(Poly *List)
{
     Poly *Position;
     Position=List->next;
     while(Position!=NULL)
     {
        printf("%dX^%d",Position->coeff,Position->pow);
        Position=Position->next;
        if(Position!=NULL && Position->coeff>=0)
        {
             printf("+");
        }
     }
     printf("\n");
}
void Addition(Poly *Poly1,Poly *Poly2,Poly *Result)
{
    Poly1=Poly1->next;
    Poly2=Poly2->next;
    Poly *Position;
    Position=Result;
    while(Poly1!=NULL && Poly2!=NULL)
    {
        Poly *newnode=(Poly*)malloc(sizeof(Poly));
        if(Poly1->pow==Poly2->pow)
        {
            newnode->coeff=Poly1->coeff+Poly2->coeff;
            newnode->pow=Poly1->pow;
            Poly1=Poly1->next;
            Poly2=Poly2->next;
        }
        else if(Poly1->pow>Poly2->pow)
        {
            newnode->coeff=Poly1->coeff;
            newnode->pow=Poly1->pow;
            Poly1=Poly1->next;
        }
         else if(Poly1->pow<Poly2->pow)
        {
            newnode->coeff=Poly2->coeff;
            newnode->pow=Poly2->pow;
            Poly2=Poly2->next;
        }

    newnode->next=NULL;
    Position->next=newnode;
    Position=newnode;
    }
    while(Poly1!=NULL||Poly2!=NULL)
    {
         {
        Poly *newnode=(Poly*)malloc(sizeof(Poly));
        if(Poly1!=NULL)
        {
            newnode->coeff=Poly1->coeff;
            newnode->pow=Poly1->pow;
            Poly1=Poly1->next;
        }
        else if(Poly2!=NULL)
        {
            newnode->coeff=Poly2->coeff;
            newnode->pow=Poly2->pow;
            Poly2=Poly2->next;
        }
    newnode->next=NULL;
    Position->next=newnode;
    Position=newnode;
    }
    }
}
void Subtraction(Poly *Poly1,Poly *Poly2,Poly *Result)
{
    Poly1=Poly1->next;
    Poly2=Poly2->next;
    Poly *Position;
    Position=Result;
    while(Poly1!=NULL && Poly2!=NULL)
    {
        Poly *newnode=(Poly*)malloc(sizeof(Poly));
        if(Poly1->pow==Poly2->pow)
        {
            newnode->coeff=Poly1->coeff-Poly2->coeff;
            newnode->pow=Poly1->pow;
            Poly1=Poly1->next;
            Poly2=Poly2->next;
        }
        else if(Poly1->pow>Poly2->pow)
        {
            newnode->coeff=Poly1->coeff;
            newnode->pow=Poly1->pow;
            Poly1=Poly1->next;
        }
         else if(Poly1->pow<Poly2->pow)
        {
            newnode->coeff=-Poly2->coeff;
            newnode->pow=Poly2->pow;
            Poly2=Poly2->next;
        }

    newnode->next=NULL;
    Position->next=newnode;
    Position=newnode;
    }
    while(Poly1!=NULL||Poly2!=NULL)
    {
         {
        Poly *newnode=(Poly*)malloc(sizeof(Poly));
        if(Poly1!=NULL)
        {
            newnode->coeff=Poly1->coeff;
            newnode->pow=Poly1->pow;
            Poly1=Poly1->next;
        }
        else if(Poly2!=NULL)
        {
            newnode->coeff=-Poly2->coeff;
            newnode->pow=Poly2->pow;
            Poly2=Poly2->next;
        }
    newnode->next=NULL;
    Position->next=newnode;
    Position=newnode;
    }
    }
}
void Differentiation(Poly *Poly1,Poly *Result)
{
    Poly1=Poly1->next;
    Poly *Position;
    Position=Result;
    while(Poly1!=NULL)
    {
         Poly *newnode=(Poly*)malloc(sizeof(Poly));
         newnode->coeff=Poly1->coeff*Poly1->pow;
         newnode->pow=Poly1->pow-1;
         newnode->next=NULL;
         Poly1=Poly1->next;
         Position->next=newnode;
         Position=newnode;
    }
} 
int main()
{
   int choice;
   Poly *Poly1=(Poly*)malloc(sizeof(Poly));
   Poly *Poly2=(Poly*)malloc(sizeof(Poly));
   Poly *Result=(Poly*)malloc(sizeof(Poly));
   Poly1->next=NULL;
   Poly2->next=NULL;
   Result->next=NULL;
   while(1)
   {
       printf("\n     POLYNOMIAL ADT        \n");
       printf("1.Addition 2.Subtraction 3.Differentiation 4.Exit\n");
       printf("Enter your choice: ");
       scanf("%d",&choice);
       switch(choice)
       {
          case 1:
            printf("Enter the values of the first polynomial: \n");
            Create(Poly1);
            printf("Enter the values of the second polynomial: \n");
            Create(Poly2);
            printf("The 1st polynomial is : \n");
            Display(Poly1);
            printf("The 2nd polynomial is : \n");
            Display(Poly2);
            printf("The addition of two polynomials is\n");
            Addition(Poly1,Poly2,Result);
            Display(Result);
            break;
          case 2:
            printf("Enter the values of the first polynomial: \n");
            Create(Poly1);
            printf("Enter the values of the second polynomial: \n");
            Create(Poly2);
            printf("The 1st polynomial is : \n");
            Display(Poly1);
            printf("The 2nd polynomial is : \n");
            Display(Poly2);
            printf("The subtraction of two polynomials is\n");
            Subtraction(Poly1,Poly2,Result);
            Display(Result);
            break;
          case 3:
            printf("Enter the values of the first polynomial: \n");
            Create(Poly1);
            printf("The polynomial is : \n");
            Display(Poly1);
            printf("The differentiation of polynomial is\n");
            Differentiation(Poly1,Result);
            Display(Result);
            break;

         case 4:
            exit(0);
            break;
   }
   }
   return 0;
}
