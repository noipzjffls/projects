#include<bits/stdc++.h>
using namespace std;
int n,ex,ey,dx[]={-1,0,0,1},dy[]={0,-1,1,0},front=1,rear=1;
char maps[1001][1001];
bool vis[1001][1001];
struct node
{
    int x,y,t;
}q[1000001];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>maps[i][j];
        }
    }
    scanf("%d%d%d%d",&q[1].x,&q[1].y,&ex,&ey);
    vis[q[1].x][q[1].y]=true;
    while(front<=rear)
    {
        node qf=q[front];
        for(int i=0;i<4;i++)
        {
            int nx=qf.x+dx[i],ny=qf.y+dy[i];
            if(nx<1||ny<1||nx>n||ny>n||vis[nx][ny]||maps[nx][ny]=='1')continue;
            vis[nx][ny]=true;
            q[++rear]=(node){nx,ny,qf.t+1};
            if(nx==ex&&ny==ey)
            {
                printf("%d",q[rear].t);
                return 0;
            }
        }
        front++;
    }
    return 0;
}