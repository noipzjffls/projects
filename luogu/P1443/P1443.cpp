#include<bits/stdc++.h>
using namespace std;
int n,m,dx[]={-2,-2,-1,-1,1,1,2,2},dy[]={-1,1,-2,2,-2,2,-1,1},front=1,rear=1,ans[401][401];
bool vis[401][401];
struct node
{
    int x,y,step;
}q[160001];
int main()
{
    scanf("%d%d%d%d",&n,&m,&q[1].x,&q[1].y);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans[i][j]=-1;
    ans[q[1].x][q[1].y]=0;
    vis[q[1].x][q[1].y]=true;
    while(front<=rear)
    {
        node qf=q[front];
        for(int i=0;i<8;i++)
        {
            int nx=qf.x+dx[i],ny=qf.y+dy[i];
            if(nx<1||ny<1||nx>n||ny>m||vis[nx][ny])continue;
            q[++rear]=(node){nx,ny,qf.step+1};
            ans[nx][ny]=q[rear].step;
            vis[nx][ny]=true;
        }
        front++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)printf("%-5d",ans[i][j]);
        putchar('\n');
    }
    return 0;
}