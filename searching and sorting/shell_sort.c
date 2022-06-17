
// C PROGRAM TO IMPLEMENT SHELL SORT

#include <stdio.h> 
void ShellSort(int a[], int n) 
{ 
    int gap, i, j, temp; 
    for (gap = n / 2; gap > 0; gap /= 2) 
    { 
        for (i = gap; i < n; i += 1) 
        { 
            temp = a[i]; 
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) 
            { 
                a[j] = a[j - gap]; 
            } 
            a[j] = temp; 
        } 
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
    ShellSort(a, n); 
    printf("The sorted elements are : "); 
    for (i = 0; i < n; i++) 
    printf("%d ", a[i]); 
    return 0; 
} 

