#include<iostream>
using namespace std;
int n,m,f,sx,sy,ex,ey,front,rear,dx[]={-1,0,0,1},dy[]={0,-1,1,0};
char a[21][21];
struct node
{
    int x,y,cnt;
}q[1001];
int main()
{
    while(1)
    {
        cin>>n>>m;
        if(!n&&!m)break;
        f=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                }
                if(a[i][j]=='*')
                {
                    ex=i;
                    ey=j;
                }
            }
        }
        q[1].x=sx;
        q[1].y=sy;
        q[1].cnt=0;
        front=rear=1;
        while(front<=rear)
        {
            for(int i=0;i<4;i++)
            {
                int nx=q[front].x+dx[i],ny=q[front].y+dy[i];
                if(nx>0&&ny>0&&nx<=n&&ny<=m&&a[nx][ny]-'#')
                {
                    q[++rear].x=nx;
                    q[rear].y=ny;
                    q[rear].cnt=q[front].cnt+1;
                    a[nx][ny]='#';
                    if(nx==ex&&ny==ey)
                    {
                        cout<<q[rear].cnt<<endl;
                        f=1;
                        break;
                    }
                }
            }
            if(f)break;
            front++;
        }
        if(!f)cout<<"-1\n";
    }
}
