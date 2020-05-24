#include<bits/stdc++.h>
using namespace std;
int t,n,m,X,Y,ans,dx[]={-2,-2,-1,-1,1,1,2,2},dy[]={-1,1,-2,2,-2,2,-1,1};
bool vis[10][10];
void dfs(int x,int y,int k)
{
    if(k==n*m)
    {
        ans++;
        return;
    }
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0||ny<0||nx>=n||ny>=m||vis[nx][ny])continue;
        vis[nx][ny]=true;
        dfs(nx,ny,k+1);
        vis[nx][ny]=false;
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        memset(vis,false,sizeof(vis));
        ans=0;
        cin>>n>>m>>X>>Y;
        vis[X][Y]=true;
        dfs(X,Y,1);
        cout<<ans<<endl;
    }
}