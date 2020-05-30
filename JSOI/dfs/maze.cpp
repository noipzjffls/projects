#include<bits/stdc++.h>
using namespace std;
int m,n,x,y,dx[]={0,0,-1,1},dy[]={-1,1,0,0},route[401],flag[21][21];
bool vis[21][21];
void print(int k)
{
    cout<<"(1,1)";
    int a=1,b=1;
    for(int i=1;i<k;i++)
    {
        a+=dx[route[i]],b+=dy[route[i]];
        cout<<"->("<<a<<','<<b<<')';
    }
    exit(0);
}
void dfs(int dep)
{
    if(x==n&&y==m)
    {
        print(dep);
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&nx<=n&&ny>0&&ny<=m&&!flag[nx][ny]&&!vis[nx][ny])
        {
            vis[nx][ny]=1;
            x=nx,y=ny,route[dep]=i;
            dfs(dep+1);
            vis[x][y]=0;
            x-=dx[i],y-=dy[i];
        }
    }
}
int main()
{
    scanf("%d",&n);
    m=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%1d",&flag[i][j]);
        }
    }
    vis[1][1]=true;
    x=y=1;
    dfs(1);
    return 0;
}