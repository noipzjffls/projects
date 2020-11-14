/*
User: shenyouran
Problem: 2819
Algorithm: DFS
Language: C/C++
Record ID: 74886
Submit Time: 2020-10-24 14:27:06
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int n,m,a[101][101],ans[101][101];
const int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
void dfs(int x,int y,int cost,bool f)
{
    if(cost>=ans[x][y])return;
    ans[x][y]=cost;
    if(x==n&&y==n)return;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||ny<1||nx>n||ny>n)continue;
        if(a[nx][ny]!=-1)
        {
            if(a[nx][ny]==a[x][y])dfs(nx,ny,cost,false);
            else dfs(nx,ny,cost+1,false);
        }
        else if(!f)
        {
            a[nx][ny]=a[x][y];
            dfs(nx,ny,cost+2,true);
            a[nx][ny]=-1;
        }
    }
}
int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
int main()
{
    memset(a,-1,sizeof(a));
    memset(ans,0x3f,sizeof(ans));
    n=read(),m=read();
    while(m--)a[read()][read()]=read();
    dfs(1,1,0,false);
    if(ans[n][n]==0x3f3f3f3f)puts("-1");
    else printf("%d",ans[n][n]);
    return 0;
}