#include<stdio.h>
#include<limits.h>

void main()
{
    int n,i,j,source,d,round,v;
    int dist[50],visited[50],adj[50][50];
    int min,minimum;
    printf("How many nodes:");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=0;
    }
    printf("Enter the source node:");
    scanf("%d",&source);
    dist[source]=0;
    for(round=0;round<n;round++)
    {
        min=INT_MAX;
        for(v=0;v<n;v++)
        {
            if(visited[v]==0 && dist[v]<min)
            {
                min=dist[v];
                minimum=v;
            }
        }
        visited[minimum]=1;
        for(d=0;d<n;d++)
        {
            if(!visited[d] && adj[minimum][d] && dist[minimum] !=INT_MAX && dist[minimum]+adj[minimum][d]<dist[d])
            {
                dist[d]=dist[minimum]+adj[minimum][d];
            }
        }
    }
    printf("\nDistance from source\n");
    for(i=0;i<n;i++)
    {
        if(dist[i]==INT_MAX)
        {
            printf("%d\t\tINF\n",i);
        }
        else
        {
            printf("%d\t\t%d\n",i,dist[i]);
        }
    }
}
