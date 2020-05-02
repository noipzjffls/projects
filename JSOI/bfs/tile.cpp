#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
int h,w,dx[]={-1,0,0,1},dy[]={0,-1,1,0},front=1,rear=1;
bool visit[61][61];
char c[61][61];
struct node
{
    int x,y,cnt;
}q[maxn];
int main()
{
    q[1].cnt=1;
    cin>>w>>h;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cin>>c[i][j];
            if(c[i][j]=='@')
            {
                q[1].x=i;
                q[1].y=j;
                visit[i][j]=1;
            }
        }
    }
    while(front<=rear)
    {
        for(int i=0;i<4;i++)
        {
            int a=q[front].x+dx[i],b=q[front].y+dy[i];
            if(a>0&&b>0&&a<=h&&b<=w&&!visit[a][b]&&c[a][b]=='.')
            {
                q[++rear].x=a;
                q[rear].y=b;
                q[rear].cnt=q[front].cnt+1;
                visit[a][b]=1;
            }
        }
        front++;
    }
    cout<<rear<<endl;
}
