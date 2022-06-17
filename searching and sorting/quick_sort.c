
// C PROGRAM TO IMPLEMENT QUICK SORT

#include <stdio.h> 
void QuickSort(int a[], int left, int right) 
{ 
    int i, j, temp, pivot; 
    if (left < right) 
    { 
        pivot = left; 
        i = left + 1; 
        j = right; 
        while (i < j) 
        { 
            while (a[i] < a[pivot]) 
            i++; 
            while (a[j] > a[pivot]) 
            j--; 
            if (i < j) 
            { 
                temp = a[i]; 
                a[i] = a[j]; 
                a[j] = temp; 
            } 
        } 
        temp = a[pivot]; 
        a[pivot] = a[j]; 
        a[j] = temp; 
        QuickSort(a, left, j - 1); 
        QuickSort(a, j + 1, right); 
    } 
}

int main() 
{ 
    int i, n, a[10]; 
    printf("Enter the limit : "); 
    scanf("%d", &n); 
    printf("Enter the elements : "); 
    for (i = 0; i < n; i++) 
    scanf("%d", &a[i]); 
    QuickSort(a, 0, n - 1); 
    printf("The sorted elements are : "); 
    for (i = 0; i < n; i++) 
    printf("%d ", a[i]); 
    return 0; 
} 