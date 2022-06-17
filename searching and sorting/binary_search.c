
// C PROGRAM TO IMPLEMENT BINARY SEARCH

#include <stdio.h> 
int BinarySearch(int a[], int n, int key) 
{ 
    int first, last, mid; 
    first = 0; 
    last = n - 1; 
    while (first <= last) 
    { 
        mid = (first + last) / 2; 
        if (a[mid] == key) 
        return mid; 
        else if (a[mid] < key) 
        first = mid + 1; 
        else 
        last = mid - 1; 
    }
return -1; 
}
int main() 
{ 
    int n, a[10], i, key, pos; 
    printf("Enter the limit : "); 
    scanf("%d", &n); 
    printf("Enter the elements in sorted order : "); 
    for (i = 0; i < n; i++) 
    scanf("%d", &a[i]); 
    printf("Enter the element to search : "); 
    scanf("%d", &key); 
    pos = BinarySearch(a, n, key); 
    if (pos != -1) 
    printf("Element found at location : %d", pos); 
    else 
    printf("Element not found."); 
    return 0; 
} 
