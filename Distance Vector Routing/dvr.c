#include <stdio.h>
#include <stdlib.h>
#define SIZE 25
void main()
{
    int i,j,k,n,dist[SIZE][SIZE];
printf("How many routers: ");
scanf("%d",&n);
printf("Enter the cost matrix\n");
for(i=0;i<n;i++)
{
    printf("Router %d\n",i);
    for(j=0;j<n;j++)
    {
        scanf(" %d",&dist[i][j]);
    }
}
printf("\nInitial routing table is\n");
for(i=0;i<n;i++)
{
    printf("Router %d\n",i);
    for(j=0;j<n;j++)
    {
        printf("%d ",dist[i][j]);
    }
    printf("\n");
}
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
            if(dist[i][j] > dist[i][k] + dist[k][j])
            {
                dist[i][j]=dist[i][k] + dist[k][j];
            }
        }
    }
}
printf("\nRouting Table is\n");
for(i=0;i<n;i++)
{
    printf("Router %d\n",i);
    for(j=0;j<n;j++)
    {
        printf("%d ",dist[i][j]);
    }
    printf("\n");
}
printf("\nRouting Table\n\t");
for(i=0;i<n;i++)
{
    printf("%d\t",i);
}
printf("\n");
printf("-----------");
printf("\n");
for(i=0;i<n;i++)
{
    printf("%d\t|",i);
    for(j=0;j<n;j++)
    {
        printf("%d\t|",dist[i][j]);
    }
    printf("\n");
}
}

