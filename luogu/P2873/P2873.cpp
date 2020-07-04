#include<bits/stdc++.h>
using namespace std;
int ex,ey,n,front=1,rear=1,dx[]={-1,0,0,1},dy[]={0,-1,1,0};
bool mud[1001][1001],vis[1001][1001];
struct node
{
    int x,y,step;
}q[1000001];
int main()
{
    scanf("%d%d%d",&ex,&ey,&n);
    for(int i=0,a,b;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        mud[a+500][b+500]=true;
    }
    q[1]=(node){500,500,0};
    while(front<=rear)
    {
        node f=q[front++];
        for(int i=0;i<4;i++)
        {
            int nx=f.x+dx[i],ny=f.y+dy[i];
            if(nx<0||ny<0||nx>1000||ny>1000||vis[nx][ny]||mud[nx][ny])continue;
            vis[nx][ny]=true;
            q[++rear]=(node){nx,ny,f.step+1};
            if(nx==ex+500&&ny==ey+500)
            {
                printf("%d",q[rear].step);
                return 0;
            }
        }
    }
    return 0;
}