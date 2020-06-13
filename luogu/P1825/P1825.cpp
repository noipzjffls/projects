#include<bits/stdc++.h>
using namespace std;
int n,m,sx,sy,dx[]={-1,0,0,1},dy[]={0,-1,1,0},maps[301][301],front=1,rear=1;
bool vis[301][301];
struct node
{
    int x,y,step;
}q[90001];
void travel(int &x,int &y)
{
    int temp=maps[x][y];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==x&&j==y)continue;
            if(temp==maps[i][j])
            {
                x=i;
                y=j;
                return;
            }
        }
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
            switch(ch)
            {
                case '=':
                {
                    maps[i][j]=-1;
                    break;
                }
                case '@':
                {
                    sx=i;
                    sy=j;
                    break;
                }
                case '.':break;
                case '#':
                {
                    maps[i][j]=-2;
                    break;
                }
                default:maps[i][j]=ch;
            }
        }
    }
    vis[sx][sy]=true;
    q[1]=(node){sx,sy,0};
    while(front<=rear)
    {
        node t=q[front];
        for(int i=0;i<4;i++)
        {
            int nx=t.x+dx[i],ny=t.y+dy[i];
            if(nx>0&&ny>0&&nx<=n&&ny<=m&&maps[nx][ny]!=-2&&!vis[nx][ny])
            {
                vis[nx][ny]=true;
                if(maps[nx][ny]>0)travel(nx,ny);
                q[++rear]=(node){nx,ny,t.step+1};
                if(maps[q[rear].x][q[rear].y]==-1)
                {
                    printf("%d",q[rear].step);
                    return 0;
                }
            }
        }
        front++;
    }
    return 0;
}