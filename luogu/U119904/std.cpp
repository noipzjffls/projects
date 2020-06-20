#include<bits/stdc++.h>
using namespace std;
int t,m,n,x,y,ans[21][21],dx[]={0,0,-1,1},dy[]={-1,1,0,0},route[401],r[401],maps[21][21];
bool vis[21][21],flag;
void print(int k)
{
    printf("(1,1)");
    int a=1,b=1;
    for(int i=1;i<=k;i++)
    {
        a+=dx[route[i]],b+=dy[route[i]];
        printf("->(%d,%d)",a,b);
    }
    putchar('\n');
}
void dfs(int dep,int step)
{
    if(x==n&&y==m)
    {
        if(step<ans[x][y])
        {
            flag=true;
            ans[x][y]=step;
            for(int i=1;i<=step;i++)route[i]=r[i];
        }
        return;
    }
    if(step>ans[x][y])return;
    ans[x][y]=step;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&nx<=n&&ny>0&&ny<=m&&!maps[nx][ny]&&!vis[nx][ny])
        {
            vis[nx][ny]=true;
            x=nx,y=ny,r[dep]=i;
            dfs(dep+1,step+1);
            vis[x][y]=false;
            x-=dx[i],y-=dy[i];
        }
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        flag=false;
        memset(vis,false,sizeof(vis));
        memset(ans,0x3f,sizeof(ans));
        scanf("%d",&n);
        m=n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%1d",&maps[i][j]);
            }
        }
        vis[1][1]=true;
        x=y=1;
        dfs(1,0);
        if(flag)
        {
            printf("%d\n",ans[n][m]);
            print(ans[n][m]);
        }
        else puts("-1");
    }
    return 0;
}