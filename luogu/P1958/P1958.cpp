#include<cstdio>
int a,b,n,cnt,dx[]={0,1},dy[]={1,0};
bool vis[17][17];
void dfs(int x,int y)
{
    if(x==a&&y==b)
    {
        cnt++;
        return;
    }
    for(int i=0;i<2;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||ny<1||nx>a||ny>b||vis[nx][ny])continue;
        vis[nx][ny]=true;
        dfs(nx,ny);
        vis[nx][ny]=false;
    }
}
int main()
{
    scanf("%d%d%d",&a,&b,&n);
    for(int i=0,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        vis[x][y]=true;
    }
    vis[1][1]=true;
    dfs(1,1);
    printf("%d",cnt);
    return 0;
}