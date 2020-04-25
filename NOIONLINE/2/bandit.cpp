#include<bits/stdc++.h>
using namespace std;
int n,m,c1,c2,d,beginx,beginy,endx,endy,dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1},Dx[]={1,-1,0,0},Dy[]={0,0,1,-1},front,rear;
string maps[351][351],newmap[351][351];
void find(int x,int y,int z)
{
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(abs(i-x)+abs(j-y)<z)newmap[i][j]="#";
}
struct node
{
    int x,y,left1,left2,cnt;
}q[122501];
void cal(int f,int &r,int nx,int ny,bool b1,bool b2)
{
    q[++r].x=nx;
    q[r].y=ny;
    q[r].cnt=q[f].cnt+1;
    q[r].left1=q[f].left1-b1;
    q[r].left2=q[f].left2-b2;
    if(q[r].x==endx&&q[r].y==endy)
    {
        printf("%d %d %d",q[r].cnt,c1-q[r].left1,c2-q[r].left2);
        exit(0);
    }
}
int transfer(string s)
{
    int num=0;
    for(int i=0;i<s.size();i++)num=(num<<3)+(num<<1)+(s[i]^48);
    return num;
}
int main()
{
    freopen("bandit.in","r",stdin);
    freopen("bandit.out","w",stdout);
    cin>>n>>m>>c1>>c2>>d;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>maps[i][j];
            if(maps[i][j]=="S")
            {
                beginx=i;
                beginy=j;
            }
            if(maps[i][j]=="T")
            {
                endx=i;
                endy=j;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(maps[i][j]!="S"&&maps[i][j]!="T"&&maps[i][j]!=".")
            {
                int x=transfer(maps[i][j]);
                find(i,j,x);
            }
        }
    }
    front=rear=1;
    q[1].x=beginx;
    q[1].y=beginy;
    q[1].left1=c1;
    q[1].left2=c2;
    while(front<=rear)
    {
        for(int i=0;i<8;i++)
        {
            int nx=q[front].x+dx[i],ny=q[front].y+dy[i];
            if(nx>0&&ny>0&&nx<=n&&ny<=m&&newmap[nx][ny]!="#"&&(maps[nx][ny]=="T"||maps[nx][ny]=="."))cal(front,rear,nx,ny,0,0);
        }
        if(q[front].left1>0)
        {
            for(int i=0;i<8;i++)
            {
                int nx=q[front].x+dx[i],ny=q[front].y+dy[i];
                if(nx>0&&ny>0&&nx<=n&&ny<=m&&(maps[nx][ny]=="T"||maps[nx][ny]=="."))cal(front,rear,nx,ny,1,0);
            }
        }
        if(q[front].left2>0)
        {
            for(int i=0;i<4;i++)
            {
                int nx=q[front].x+Dx[i]*d,ny=q[front].y+Dy[i]*d;
                if(nx>0&&ny>0&&nx<=n&&ny<=m&&newmap[nx][ny]!="#"&&(maps[nx][ny]=="T"||maps[nx][ny]=="."))cal(front,rear,nx,ny,0,1);
            }
        }
        if(q[front].left1>0&&q[front].left2>0)
        {
            for(int i=0;i<4;i++)
            {
                int nx=q[front].x+Dx[i]*d,ny=q[front].y+Dy[i]*d;
                if(nx>0&&ny>0&&nx<=n&&ny<=m&&(maps[nx][ny]=="T"||maps[nx][ny]==".")) cal(front,rear,nx,ny,1,1);
            }
        }
        front++;
    }
    printf("-1");
    return 0;
}