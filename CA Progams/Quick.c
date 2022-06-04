#include <stdio.h>
int  partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while(i<=j)
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    // swap a[low] with a[j]
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
void quicksort(int a[], int low, int high)
{
    int partitionIn; // index of pivot element after partition
    if (low < high)
    {
        partitionIn = partition(a, low, high);
        quicksort(a, low, partitionIn - 1); // left  subarray
        quicksort(a, partitionIn+1, high);    // right subarray
    }
}
void printarray(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{
    int a[] = {4,33, 21, 2, 7, 8, 1};
    int size = 7;
    printarray(a, size);
    quicksort(a, 0, size - 1);
    printf("After sorting\n");
    printarray(a, size);
    return 0;
}