#include<bits/stdc++.h>
using namespace std;
int n,dx[]={0,-1,0,0,1},dy[]={0,0,-1,1,0},front=1,rear=1,land[305][305],vis[305][305];
struct node
{
    int x,y,t;
}q[90005];
int main()
{
    memset(land,0x3f,sizeof(land));
    cin>>n;
    for(int i=0,a,b,c;i<n;i++)
    {
        cin>>a>>b>>c;
        for(int i=0;i<5;i++)
        {
            int nx=a+dx[i],ny=b+dy[i];
            if(nx<0||ny<0||nx>304||ny>304)continue;
            land[nx][ny]=min(land[nx][ny],c);
        }
    }
    while(front<=rear)
    {
        node qf=q[front];
        for(int i=1;i<5;i++)
        {
            int nx=qf.x+dx[i],ny=qf.y+dy[i];
            if(nx<0||ny<0||nx>304||ny>304||vis[nx][ny]||qf.t+1>=land[nx][ny])continue;
            vis[nx][ny]=true;
            q[++rear]=(node){nx,ny,qf.t+1};
            if(land[nx][ny]==0x3f3f3f3f)
            {
                printf("%d",q[rear].t);
                return 0;
            }
        }
        front++;
    }
    puts("-1");
    return 0;
}