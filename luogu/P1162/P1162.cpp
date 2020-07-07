#include<bits/stdc++.h>
using namespace std;
int n,maps[32][32],dx[]={-1,0,0,1},dy[]={0,-1,1,0};
bool vis[32][32];
void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0||ny<0||nx>n+1||ny>n+1||maps[nx][ny]!=2||vis[nx][ny])continue;
        maps[nx][ny]=0;
        vis[nx][ny]=true;
        dfs(nx,ny);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&maps[i][j]);
            if(!maps[i][j])maps[i][j]=2;
        }
    }
    for(int i=1;i<=n+1;i++)maps[i][0]=maps[0][i]=maps[i][n+1]=maps[n+1][i]=2;
    dfs(0,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)printf("%d ",maps[i][j]);
        putchar('\n');
    }
    return 0;
}