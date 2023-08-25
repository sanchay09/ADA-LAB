#include<stdio.h>
#include<conio.h>

void dijkstra(int n,int cost[10][10],int src)
{
    int i,j,u,dis[10],vis[10],min;
    for(i=1;i<=n;i++)
    {
        dis[i]=cost[src][i];
        vis[i]=0;
    }
    
    vis[src]=1;
    for(i=1;i<=n;i++)
    {
        min=999;
        for(j=1;j<=n;j++)
        {
            if(vis[j]==0 && dis[j]<min)
            {
                min=dis[j];
                u=j;
            }
        }
        
        vis[u]=1;
        for(j=1;j<=n;j++)
        {
            if(vis[j]==0 && dis[u]+cost[u][j]<dis[j])
            {
                dis[j]=dis[u]+cost[u][j];
            }
        }
    }

    printf("Shortest Path:\n");
    for(i=1;i<=n;i++)
    printf("%d->%d=%d\n",src,i,dis[i]);
}

void main()
{
    int src,j,cost[10][10],n,i;

    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    
    printf("\nEnter the cost adjacency matrix: \n");
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
            
    printf("\nEnter the source vertex: ");
    scanf("%d",&src);
    
    dijkstra(n,cost,src);
}