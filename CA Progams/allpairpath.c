#include <stdio.h>
#include <stdlib.h>
int cost[10][10], a[10][10];
void all_paths(int[10][10], int[10][10], int);
int min(int, int);

void main()
{
    int i, j, n;
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    printf("\nEnter the adjcency matrix:");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);
    all_paths(cost, a, n);
    printf("\nThe shortest path is");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
void all_paths(int cost[10][10], int a[10][10], int n)
{
    int i, j, k;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = cost[i][j];
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}
int min(int a, int b)
{
    return (a < b) ? a : b;
}