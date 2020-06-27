#include<bits/stdc++.h>
using namespace std;
int ans[21][21],dx[]={-2,-2,-1,-1,1,1,2,2,-2,-2,2,2},dy[]={-1,1,-2,2,-2,2,-1,1,-2,2,-2,2};
bool vis[21][21];
void dfs(int x,int y,int t)
{
    if(t>=ans[x][y])return;
    ans[x][y]=t;
    for(int i=0;i<12;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||ny<1||nx>20||ny>20||vis[nx][ny])continue;
        vis[nx][ny]=true;
        dfs(nx,ny,t+1);
        vis[nx][ny]=false;
    }
}
int main()
{
    memset(ans,0x3f,sizeof(ans));
    vis[1][1]=true;
    dfs(1,1,0);
    for(int i=1,x,y;i<3;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",ans[x][y]);
    }
    return 0;
}