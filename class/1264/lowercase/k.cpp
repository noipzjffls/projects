/*
User: shenyouran
Problem: 2159
Algorithm: Graph Theory, Shortest Path, Dijkstra
Language: C/C++
Record ID: 75892
Submit Time: 2020-11-14 15:34:59
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,head[50001],dis[50001];
bool vis[50001];
struct edge
{
    int nxt,to,w;
}e[100001];
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
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    dijkstra(1);
    printf("%d",dis[n]);
    return 0;
}