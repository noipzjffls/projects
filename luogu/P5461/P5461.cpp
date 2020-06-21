#include<bits/stdc++.h>
using namespace std;
int n;
bool a[1025][1025];
void dfs(int x,int y,int xx,int yy)
{
    if(x==xx&&y==yy)return;
    int nx=(x+xx)>>1,ny=(y+yy)>>1;
    for(int i=x;i<=nx;i++)
    {
        for(int j=y;j<=ny;j++)
        {
            a[i][j]=true;
        }
    }
    dfs(x,ny+1,nx,yy);
    dfs(nx+1,y,xx,ny);
    dfs(nx+1,ny+1,xx,yy);
}
int main()
{
    scanf("%d",&n);
    dfs(1,1,1<<n,1<<n);
    for(int i=1;i<=1<<n;i++)
    {
        for(int j=1;j<=1<<n;j++)
        {
            putchar(!a[i][j]^48);
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}