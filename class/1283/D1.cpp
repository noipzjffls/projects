/*
User: shenyouran
Problem: 2565
Algorithm: Dijkstra
Time Complexity: O(f log f + p + c)
Storage Complexity: O(f + p + c)
*/
#include<bits/stdc++.h>
using namespace std;
int f,p,c,m,s,cnt,head[501],dis[501],ans[101];
bool vis[501];
struct edge
{
    int nxt,to,w;
}e[2001];
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
    e[++cnt].nxt=head[u];
    e[cnt].to=v;
    e[cnt].w=w;
    head[u]=cnt;
}
void dijkstra(int s)
{
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
int main()
{
    memset(dis,0x3f,sizeof(dis));
    scanf("%d%d%d%d",&f,&p,&c,&m);
    while(p--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    dijkstra(1);
    for(int i=1,x;i<=c;i++)
    {
        scanf("%d",&x);
        if(dis[x]<=m)ans[++s]=i;
    }
    printf("%d\n",s);
    for(int i=1;i<=s;i++)printf("%d\n",ans[i]);
    return 0;
}