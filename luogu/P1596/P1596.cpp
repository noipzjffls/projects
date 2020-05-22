#include<cstdio>
#include<iostream>
int n,m,dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1},cnt;
char maps[101][101];
void dfs(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&ny>0&&nx<=n&&ny<=m&&maps[nx][ny]=='W')
        {
            maps[nx][ny]='.';
            dfs(nx,ny);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        getchar();
        for(int j=1;j<=m;j++)maps[i][j]=getchar();
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(maps[i][j]=='W')
            {
                cnt++;
                dfs(i,j);
            }
        }
    }
    printf("%d",cnt);
}