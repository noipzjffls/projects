/*
User: shenyouran
Problem: 3178
Algorithm: Dijkstra
Time Complexity: O(n log n + m + q)
Storage Complexity: O(n + m)
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,q,cnt,head[100001],dis[100001][2];
struct edge
{
    int nxt,to;
}e[200001];
struct node
{
    int pos,dis1,dis2;
    bool operator<(const node &x)const
    {
        if(dis1!=x.dis1)return dis1>x.dis1;
        return dis2>x.dis2;
    }
};
void add(int u,int v)
{
    e[++cnt].nxt=head[u];
    e[cnt].to=v;
    head[u]=cnt;
}
void dijkstra(int s)
{
    dis[s][0]=0;
    priority_queue<node>Q;
    Q.push((node){s,dis[s][0],dis[s][1]});
    while(Q.size())
    {
        int x=Q.top().pos;
        Q.pop();
        for(int i=head[x];i;i=e[i].nxt)
        {
            int y=e[i].to;
            if(dis[y][1]>dis[x][0]+1)
            {
                dis[y][1]=dis[x][0]+1;
                Q.push((node){y,dis[y][0],dis[y][1]});
            }
            if(dis[y][0]>dis[x][1]+1)
            {
                dis[y][0]=dis[x][1]+1;
                Q.push((node){y,dis[y][0],dis[y][1]});
            }
        }
    }
}
int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
int main()
{
    memset(dis,0x3f,sizeof(dis));
    n=read(),m=read(),q=read();
    while(m--)
    {
        int u=read(),v=read();
        add(u,v);
        add(v,u);
    }
    dijkstra(1);
    while(q--)
    {
        int a=read(),L=read();
        if(dis[a][L&1]<=L)puts("Yes");
        else puts("No");
    }
    return 0;
}