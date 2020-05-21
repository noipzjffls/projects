#include<bits/stdc++.h>
using namespace std;
int n,m,t,sx,sy,ex,ey,dx[]={-1,0,0,1},dy[]={0,-1,1,0},ans;
bool flag[6][6],vis[6][6];
void dfs(int x,int y)
{
    if(x==ex&&y==ey)
    {
        ans++;
        return;
    }
    vis[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||ny<1||nx>n||ny>m||flag[nx][ny]||vis[nx][ny])continue;
        dfs(nx,ny);
        vis[nx][ny]=false;
    }
}
int main()
{
    scanf("%d%d%d%d%d%d%d",&n,&m,&t,&sx,&sy,&ex,&ey);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        flag[a][b]=true;
    }
    dfs(sx,sy);
    printf("%d",ans);
    return 0;
}