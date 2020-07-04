#include<bits/stdc++.h>
using namespace std;
int ex,ey,n,front=1,rear=1,dx[]={-1,0,0,1},dy[]={0,-1,1,0};
map<int,map<int,bool>>mud;
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
        mud[a][b]=true;
    }
    while(front<=rear)
    {
        node f=q[front++];
        for(int i=0;i<4;i++)
        {
            int nx=f.x+dx[i],ny=f.y+dy[i];
            if(nx<-500||ny<-500||nx>500||ny>500||mud[nx][ny])continue;
            mud[nx][ny]=true;
            q[++rear]=(node){nx,ny,f.step+1};
            if(nx==ex&&ny==ey)
            {
                printf("%d",q[rear].step);
                return 0;
            }
        }
    }
    return 0;
}