#include<bits/stdc++.h>
using namespace std;
int m,n,front=1,rear=1,dx[]={0,0,-1,1},dy[]={-1,1,0,0},maps[21][21];
bool vis[21][21],flag;
struct node
{
    int x,y;
}q[401],last[21][21];
void print(int a,int b,bool f)
{
    if(last[a][b].x)print(last[a][b].x,last[a][b].y,true);
    printf("(%d,%d)",a,b);
    if(f)printf("->");
}
int main()
{
    scanf("%d",&n);
    m=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%1d",&maps[i][j]);
        }
    }
    vis[1][1]=true;
    q[1]=(node){1,1};
    while(front<=rear)
    {
        node f=q[front];
        for(int i=0;i<4;i++)
        {
            int nx=f.x+dx[i],ny=f.y+dy[i];
            if(nx<1||ny<1||nx>n||ny>m||vis[nx][ny]||maps[nx][ny])continue;
            vis[nx][ny]=true;
            q[++rear]=(node){nx,ny};
            last[nx][ny]=(node){f.x,f.y};
            if(nx==n&&ny==m)
            {
                flag=true;
                break;
            }
        }
        if(flag)break;
        front++;
    }
    if(flag)print(q[rear].x,q[rear].y,false);
    else puts("-1");
    return 0;
}