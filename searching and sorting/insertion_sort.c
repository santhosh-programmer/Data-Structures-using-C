
// C PROGARM TO IMPLEMENT INSERTION SORT

#include <stdio.h> 
void InsertionSort(int a[], int n) 
{ 
    int i, j, temp; 
    for (i = 1; i < n; i++) 
    { 
        temp = a[i]; 
        j = i; 
        while (j > 0 && a[j - 1] > temp) 
        { 
            a[j] = a[j - 1]; 
            j = j - 1; 
        } 
        a[j] = temp; 
    } 
}

int main() 
{ 
    int n, i, a[10]; 
    printf("Enter the limit : "); 
    scanf("%d", &n); 
    printf("Enter the elements : "); 
    for (i = 0; i < n; i++) 
    scanf("%d", &a[i]); 
    InsertionSort(a, n); 
    printf("The sorted elements are : "); 
    for (i = 0; i < n; i++) 
    printf("%d ", a[i]); 
    return 0; 
}
