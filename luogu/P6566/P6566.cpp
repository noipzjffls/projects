#include<bits/stdc++.h>
using namespace std;
int n,m,ans,sum,maxn,galaxy[2250001],dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
bool maps[1501][1501];
void dfs(int x,int y)
{
    sum++;
    maps[x][y]=false;
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||ny<1||nx>n||ny>m||!maps[nx][ny])continue;
        dfs(nx,ny);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='*')maps[i][j]=true;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!maps[i][j])continue;
            dfs(i,j);
            galaxy[sum]++;
            maxn=max(sum*galaxy[sum],maxn);
            sum=0;
        }
    }
    for(int i=0;i<=n*m;i++)ans+=bool(galaxy[i]);
    printf("%d %d",ans,maxn);
    return 0;
}