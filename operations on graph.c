#include<stdio.h>
#include<stdlib.h>
int a[20][20],s[20],n;
void bfs(int u)
{
    int f,r,q[20],v;
    printf("the node visited from %d",u);
    f=0;
    r=-1;
    q[++r]=u;
    s[u]=1;
    printf("%d",u);
    while(f<=r)
    {
        u=q[f++];
        for(v=0;v<n;v++)
        {
            if(a[u][v]==1)
            {
                if(s[v]==0)
                {
                    printf("%d",v);
                    s[v]=1;
                    q[++r]=v;
                }
            }
        }
    }
    printf("\n");
}
void dfs(int u)
{
    int v;
    printf("%d",u);
    for(v=0;v<n;v++)
    {
        if(a[u][v]==1 && s[v]==0)
        dfs(v);
    }
}
int main()
{
    int i,j,choice,source,s1;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
    for(;;)
    {
        printf("1.bfs\n2.dfs\n3.exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("enter the source node\n");
                    scanf("%d",&s1);
                    bfs(s1);
                    break;
                    case 2: for(source=0;source<n;source++)
                            {
                                for(i=0;i<n;i++)
                                s[i]=0;
                                printf("the node visited from %d",source);
                                dfs(source);
                                printf("\n");

                            }
                            break;
                            case 3: exit(0);
                            default: printf("invalid choice\n");
        }
    }
    return 0;
}                    