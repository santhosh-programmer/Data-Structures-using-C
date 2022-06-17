
// C PROGARM TO IMPLEMENT BUBBLE SORT

#include <stdio.h> 
void BubbleSort(int a[], int n) 
{ 
    int i, j, t; 
    for (i = 0; i < n - 1; i++) 
    { 
        for (j = 0; j < n - 1 - i; j++) 
        { 
            if (a[j] > a[j + 1]) 
            { 
            t = a[j]; 
            a[j] = a[j + 1]; 
            a[j + 1] = t; 
            } 
        } 
    } 
}

int main() 
{ 
    int a[10], i, n; 
    printf("Enter the limit : "); 
    scanf("%d", &n); 
    printf("Enter the numbers : "); 
    for (i = 0; i < n; i++) 
    scanf("%d", &a[i]); 
    BubbleSort(a, n); 
    printf("The sorted elements are : "); 
    for (i = 0; i < n; i++) 
    printf("%d ", a[i]); 
    return 0; 
} 