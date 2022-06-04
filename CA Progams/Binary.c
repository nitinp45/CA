#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
void linearsearch()
{
    int a[100], size, n, i;
    int flag = 0;
    clock_t begin, end;
    begin = clock();
    printf("Enter the size of array:");
    scanf("%d", &size);
    printf("Enter the array:");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d", &n);
    for (i = 0; i < size; i++)
    {
        if (a[i] == n)
            flag = 1;
        printf("Element is present int the array\n");
        printf("Time taken is=%1f", (end - begin) / CLK_TCK);
        break;
        if (i < n)
            printf("Element found at index %d", i);
        else
            printf("Element not found");
    }
    printf("\n");
}
void binarysearch()
{
    int a[100], low, high, size, n;
    int flag = 0, i, mid;
    clock_t begin, end;
    end = clock();
    printf("Enter the size of array:");
    scanf("%d", &size);
    printf("Enter the array:");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d", &n);
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (n == a[mid])
        {
            flag = 1;
            break;
        }
        else if (n < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (flag == 1)
    {
        printf("The element %d is present in the array\n", n);
        printf("Time taken is=%1f", (end - begin) / CLK_TCK);
    }
    else
    {
        printf("The element %d is not present int the array", n);
    }
    printf("\n");
}
int main()
{
    int ch, i;
    while (1)
    {
        printf("1.linear search\n");
        printf("2.Binary search\n");
        printf("3.exit\n");
        printf("Enter the chioce:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            linearsearch();
            break;
        case 2:
            binarysearch();
            break;
        case 3:
            exit(1);
        default:
            printf("Enter the wrong case\n");
        }
    }
}
