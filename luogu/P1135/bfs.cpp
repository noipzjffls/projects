#include<bits/stdc++.h>
using namespace std;
int n,goal,front=1,rear=1,a[201];
bool vis[201];
struct node
{
    int floor,step;
}q[2001];
int main()
{
    scanf("%d%d%d",&n,&q[1].floor,&goal);
    if(goal==q[1].floor)
    {
        putchar('0');
        return 0;
    }
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    while(front<=rear)
    {
        node f=q[front];
        int d[]={a[f.floor],-a[f.floor]};
        for(int i=0;i<2;i++)
        {
            node r=(node){f.floor+d[i],f.step+1};
            if(r.floor>n||r.floor<1||vis[r.floor])continue;
            q[++rear]=r;
            vis[r.floor]=true;
            if(r.floor==goal)
            {
                printf("%d",r.step);
                return 0;
            }
        }
        front++;
    }
    puts("-1");
    return 0;
}