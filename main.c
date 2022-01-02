
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

 
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partion(int arr[], int p, int r)
{
    int pivotIndex = p + rand()%(r - p + 1); 
    int pivot;
    int i = p - 1;
    int j;
    pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[r]);
    for (j = p; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
 
    }
    swap(&arr[i+1], &arr[r]);
    return i + 1;
}
 
void quick_sort(int arr[], int p, int q)
{
    int j;
    if (p < q)
    {
        j = partion(arr, p, q);
        quick_sort(arr, p, j-1);
        quick_sort(arr, j+1, q);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[MAX];
    for (int i = 0; i < n; i++)
       scanf("%d",&arr[i]);
   
    quick_sort(arr, 0, n-1); 

    for (int i = 0; i < n; i++)
         printf("%d ", arr[i]);
    return 0;
}