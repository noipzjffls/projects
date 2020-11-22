#include<bits/stdc++.h>
using namespace std;
int n,m,s,cnt,head[100001],dis[100001];
bool vis[100001];
struct edge
{
    int nxt,to,w;
}e[200001];
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
    e[++cnt]=(edge){head[u],v,w};
    head[u]=cnt;
}
void dijkstra(int s)
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
                if(!vis[y])Q.push((node){y,dis[y]});
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
    n=read(),m=read(),s=read();
    while(m--)
    {
        int u=read(),v=read(),w=read();
        add(u,v,w);
    }
    dijkstra(s);
    for(int i=1;i<=n;i++)printf("%d ",dis[i]);
    return 0;
}