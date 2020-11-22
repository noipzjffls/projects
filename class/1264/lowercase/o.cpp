/*
User: shenyouran
Problem: 2033
Algorithm: Graph Theory, Shortest Path, Dijkstra
Language: C++
Record ID: 76294
Submit Time: 2020-11-22 09:38:16
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,x,cnt,head[501],dis[501],f[501];
double ans=1LL<<60;
bool vis[501];
struct edge
{
    int nxt,to,w,c;
}e[1001];
struct node
{
    int pos,dis;
    bool operator<(const node &x)const
    {
        return dis>x.dis;
    }
};
void add(int u,int v,int w,int c)
{
    e[++cnt].nxt=head[u];
    e[cnt].to=v;
    e[cnt].w=w;
    e[cnt].c=c;
    head[u]=cnt;
}
int dijkstra(int s,int minc)
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
            if(e[i].c<minc)continue;
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
    n=read(),m=read(),x=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),l=read(),c=read();
        add(u,v,l,c);
        add(v,u,l,c);
        f[i]=c;
    }
    for(int i=1;i<=m;i++)ans=min(ans,dijkstra(1,f[i])+1.0*x/f[i]);
    printf("%d",int(ans));
    return 0;
}