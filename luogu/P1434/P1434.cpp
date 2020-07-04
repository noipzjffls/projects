#include<bits/stdc++.h>
using namespace std;
int n,m,ans,step[101][101],h[101][101],dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int dfs(int x,int y,int s)
{
    if(step[x][y])return step[x][y];
    step[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||ny<1||nx>n||ny>m||h[nx][ny]>=h[x][y])continue;
        dfs(nx,ny,s+1);
        step[x][y]=max(step[x][y],step[nx][ny]+1);
    }
    return step[x][y];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&h[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans=max(dfs(i,j,1),ans);
        }
    }
    printf("%d",ans);
    return 0;
}