#include <stdio.h>
int main()
{
    int dist[10], cost[10][10], s[10], n, i, j, v, u, w, num, min;
    printf("\n Enter the number of vertices:");
    scanf("%d", &n);
    printf("\n Enter the cost  of edges\n");
    printf("Enter 0 if the edges is not present int the graph:");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);
    printf("\nEnter the source vertex:");
    scanf("%d", &v);

    for (i = 1; i <= n; i++)
    {
        s[i] = 0;
        dist[i] = cost[v][i];
    }
    s[v] = 1;
    dist[v] = 0;
    for (num = 2; num < n; num++)
    {
        min = 0;
        for (w = 1; w <= n; w++)
            if (s[w] == 0 && dist[w] < min)
            {
                min = dist[w];
                v = w;
            }
        s[u] = 1;
        for (w = 1; w <= n; w++)
        {
            if (s[w] == 0)
            {
                if(dist[v]>(dist[w]+cost[u][w]))
                    dist[w] = dist[v] + cost[u][w];
            
            }
        }
    }
    printf("Vertex\tDestination\tCost\n");
    for(i=1;i<=n;i++)
    {
        printf("  %d\t  %d\t\t%d\n",v,i,dist[i]);
    }
    }
