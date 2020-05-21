#include<iostream>
using namespace std;
struct node
{
    int floor,cnt;
}q[2001];
int n,a,b,front=1,rear=1,c[201],flag;
bool visit[201];
void f(int s)
{
    if(s<=n&&s>0&&!visit[s])
    {
        q[++rear].floor=s;
        q[rear].cnt=q[front].cnt+1;
        visit[s]=1;
        if(s==b)
        {
            cout<<q[rear].cnt;
            flag=1;
        }
    }
}
int main()
{
    cin>>n>>a>>b;
    if(a==b)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)cin>>c[i];
    q[1].floor=a;
    while(front<=rear&&!flag)
    {
        f(q[front].floor+c[q[front].floor]);
        f(q[front].floor-c[q[front].floor]);
        front++;
    }
    if(!flag)cout<<-1;
}
