#include<cstdio>
#include<cstring>
#define max(a,b)a>b?a:b
const int maxn=101;
int n,m,dx[]={-1,0,0,1},dy[]={0,-1,1,0},front,rear,maxs,b[maxn][maxn],vis[maxn][maxn];
struct node
{
    int x,y;
}q[maxn*maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&b[i][j]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!b[i][j])continue;
            front=rear=1;
            q[1].x=i;
            q[1].y=j;
            memset(vis,0,sizeof(vis));
            vis[i][j]=1;
            while(front<=rear)
            {
                for(int k=0;k<4;k++)
                {
                    int nx=q[front].x+dx[k],ny=q[front].y+dy[k];
                    if(nx>0&&ny>0&&nx<=n&&ny<=m&&b[nx][ny]&&!vis[nx][ny])
                    {
                        q[++rear].x=nx;
                        q[rear].y=ny;
                        vis[nx][ny]=1;
                    }
                }
                front++;
            }
            maxs=max(maxs,rear);
        }
    }
    printf("%d",maxs);
}
