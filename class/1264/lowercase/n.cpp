/*
User: shenyouran
Problem: 2120
Algorithm: Graph Theory, Shortest Path, Dijkstra
Language: C++
Record ID: 76289
Submit Time: 2020-11-21 22:55:03
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,head[101],dis[101],pre[101][2],a[101][2],cnt1,cnt2,mdis,ans;
bool vis[101];
struct edge
{
    int nxt,to,w;
}e[20001];
struct node
{
    int pos,dis;
    bool operator<(const node &x)const
    {
        return dis>x.dis;
    }
};
void add(int u,int v,int w)
{
    cnt1++;
    e[cnt1].nxt=head[u];
    e[cnt1].to=v;
    e[cnt1].w=w;
    head[u]=cnt1;
}
void dijkstra1(int s)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    priority_queue<node>Q;
    Q.push((node){s,0});
    while(Q.size())
    {
        int x=Q.top().pos;
        Q.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(int i=head[x];i;i=e[i].nxt)
        {
            int y=e[i].to;
            if(dis[y]>dis[x]+e[i].w)
            {
                dis[y]=dis[x]+e[i].w;
                pre[y][0]=i;
                pre[y][1]=x;
                if(!vis[y])Q.push((node){y,dis[y]});
            }
        }
    }
}
void fprint(int k)
{
    if(pre[k][1])fprint(pre[k][1]);
    a[++cnt2][0]=pre[k][0];
    a[cnt2][1]=pre[k][1];
}
int dijkstra2(int s)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[s]=0;
    priority_queue<node>Q;
    Q.push((node){s,0});
    while(Q.size())
    {
        int x=Q.top().pos;
        Q.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(int i=head[x];i;i=e[i].nxt)
        {
            int y=e[i].to;
            if(dis[y]>dis[x]+e[i].w)
            {
                dis[y]=dis[x]+e[i].w;
                if(!vis[y])Q.push((node){y,dis[y]});
            }
        }
    }
    return dis[n];
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
    n=read(),m=read();
    while(m--)
    {
        int u=read(),v=read(),w=read();
        add(u,v,w);
        add(v,u,w);
    }
    dijkstra1(1);
    mdis=dis[n];
    fprint(n);
    a[++cnt2][0]=pre[n][0],a[cnt2][1]=n;
    for(int i=2;i<cnt2;i++)
    {
        e[a[i][0]].w<<=1;
        ans=max(ans,dijkstra2(1));
        e[a[i][0]].w>>=1;
    }
    printf("%d",ans-mdis);
    return 0;
}