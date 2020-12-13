/*
User: shenyouran
Problem: 2440
Algorithm: Dijkstra
Time Complexity: O(m + n^2 log n + t)
Storage Complexity: O(n^2 + n + m)
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,t,cnt,head[301],dis[301][301];
const int inf=0x3f3f3f3f;
bool vis[301];
struct edge
{
    int nxt,to,w;
}e[25001];
struct node
{
    int pos,maxw;
    bool operator<(const node &x)const
    {
        return maxw>x.maxw;
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
    memset(vis,false,sizeof(vis));
    dis[s][s]=0;
    priority_queue<node>Q;
    Q.push((node){s,0});
    while(Q.size())
    {
        int u=Q.top().pos,w=Q.top().maxw;
        Q.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].to,nw=max(e[i].w,w);
            if(nw<dis[s][v])
            {
                dis[s][v]=nw;
                if(!vis[v])Q.push((node){v,nw});
            }
        }
    }
}
int main()
{
    memset(dis,0x3f,sizeof(dis));
    scanf("%d%d%d",&n,&m,&t);
    while(m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(dis[a][a]==inf)dijkstra(a);
        if(dis[a][b]!=inf)printf("%d\n",dis[a][b]);
        else puts("-1");
    }
    return 0;
}