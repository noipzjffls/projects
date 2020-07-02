#include<bits/stdc++.h>
#define dist(x_1,x_2,y_1,y_2)abs(x_1-x_2)+abs(y_1-y_2)
using namespace std;
int n,m,dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
bool screen[151][151],vis[151][151];
struct node
{
    int x,y;
}q[22501];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1,x;j<=m;j++)
        {
            scanf("%1d",&x);
            screen[i][j]=x;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1,front,rear,dis;j<=m;j++)
        {
            if(screen[i][j])
            {
                printf("0 ");
                continue;
            }
            front=rear=1;
            dis=0x3f3f3f3f;
            memset(vis,false,sizeof(vis));
            q[1]=(node){i,j};
            while(front<=rear)
            {
                node f=q[front];
                for(int k=0;k<8;k++)
                {
                    int nx=f.x+dx[k],ny=f.y+dy[k],d=dist(i,nx,j,ny);
                    if(nx<1||ny<1||nx>n||ny>m||d>=dis||vis[nx][ny]||d>=dis)continue;
                    vis[nx][ny]=true;
                    q[++rear]=(node){nx,ny};
                    if(screen[nx][ny])dis=d;
                }
                front++;
            }
            printf("%d ",dis);
        }
        putchar('\n');
    }
    return 0;
}