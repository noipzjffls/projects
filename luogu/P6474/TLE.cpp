#include<bits/stdc++.h>
using namespace std;
int n,m,c1,c2,d,ex,ey,city[351][351],dx[]={-1,0,0,1,-1,-1,1,1},dy[]={0,-1,1,0,-1,1,-1,1};
bool flag[351][351],visit[351][351][16][16];
struct node
{
    int x,y,step,hide,move;
}q[12500001],ans=(node){0,0,0x7fffff,0x7fffff,0x7fffff};
void input()
{
    cin>>n>>m>>c1>>c2>>d;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            string s;
            cin>>s;
            switch(s[0])
            {
                case 'S':
                {
                    q[1].x=i;
                    q[1].y=j;
                    break;
                }
                case 'T':
                {
                    ex=i;
                    ey=j;
                    break;
                }
                case '.':break;
                default:for(int pos=0;s[pos];pos++)city[i][j]=(city[i][j]<<3)+(city[i][j]<<1)+(s[pos]^'0');
            }
        }
    }
}
bool check(node a,node b)
{
    if(a.step!=b.step)return a.step<b.step;
    if(a.hide+a.move!=b.hide+b.move)return a.hide+a.move<b.hide+b.move;
    return a.hide<b.hide;
}
void bfs()
{
    int front=1,rear=1;
    while(front<=rear)
    {
        node nf=q[front];
        if(nf.step>ans.step)
        {
            front++;
            continue;
        }
        for(int i=0;i<8;i++)
        {
            int nx=nf.x+dx[i],ny=nf.y+dy[i];
            if(nx<1||ny<1||nx>n||ny>m||city[nx][ny])continue;
            if(flag[nx][ny])
            {
                if(nf.hide>=c1||visit[nx][ny][nf.hide+1][nf.move])continue;
                visit[nx][ny][nf.hide+1][nf.move]=true;
                q[++rear]=(node){nx,ny,nf.step+1,nf.hide+1,nf.move};
                if(nx==ex&&ny==ey&&check(q[rear],ans))ans=q[rear];
            }
            else
            {
                if(visit[nx][ny][nf.hide][nf.move])continue;
                visit[nx][ny][nf.hide][nf.move]=true;
                q[++rear]=(node){nx,ny,nf.step+1,nf.hide,nf.move};
                if(nx==ex&&ny==ey&&check(q[rear],ans))ans=q[rear];
            }
        }
        for(int i=0;i<4;i++)
        {
            int nx=nf.x+dx[i]*d,ny=nf.y+dy[i]*d;
            if(nx<1||ny<1||nx>n||ny>m||city[nx][ny])continue;
            if(flag[nx][ny])
            {
                if(nf.hide>=c1||nf.move>=c2||visit[nx][ny][nf.hide+1][nf.move+1])continue;
                visit[nx][ny][nf.hide+1][nf.move+1]=true;
                q[++rear]=(node){nx,ny,nf.step+1,nf.hide+1,nf.move+1};
                if(nx==ex&&ny==ey&&check(q[rear],ans))ans=q[rear];
            }
            else
            {
                if(nf.move>=c2||visit[nx][ny][nf.hide][nf.move+1])continue;
                visit[nx][ny][nf.hide][nf.move+1]=true;
                q[++rear]=(node){nx,ny,nf.step+1,nf.hide,nf.move+1};
                if(nx==ex&&ny==ey&&check(q[rear],ans))ans=q[rear];
            }
        }
        front++;
    }
}
int main()
{
    input();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int d=city[i][j];
            if(!d)continue;
            for(int x=max(1,i-d);x<=min(n,i+d);x++)
            {
                for(int y=max(1,j-d);y<=min(m,j+d);y++)
                {
                    if(abs(x-i)+abs(y-j)<d)flag[x][y]=true;
                }
            }
        }
    }
    bfs();
    if(!ans.x)puts("-1");
    else printf("%d %d %d\n",ans.step,ans.hide,ans.move);
    return 0;
}