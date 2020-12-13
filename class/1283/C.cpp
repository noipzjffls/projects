/*
User: shenyouran
Problem: 1082
Algorithm: Dijkstra
Time Complexity: O(n log n + n + m)
Storage Complexity: O(n + m)
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans,a[100001],head1[100001],head2[100001],dis1[100001],dis2[100001];
bool vis[100001];
struct edge
{
    int nxt,to;
}e1[500001],e2[500001];
struct node
{
    int pos,dis;
    bool operator<(const node &x)const
    {
        return dis>x.dis;
    }
    bool operator>(const node &x)const
    {
        return dis<x.dis;
    }
};
void add(int u,int v)
{
    e1[++cnt].nxt=head1[u];
    e1[cnt].to=v;
    head1[u]=cnt;
    e2[cnt].nxt=head2[v];
    e2[cnt].to=u;
    head2[v]=cnt;
}
void dijkstra1(int s)
{
    memset(dis1,0x3f,sizeof(dis1));
    dis1[s]=a[s];
    priority_queue<node>Q;
    Q.push((node){s,a[s]});
    while(Q.size())
    {
        int x=Q.top().pos;
        Q.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(int i=head1[x];i;i=e1[i].nxt)
        {
            int y=e1[i].to;
            if(dis1[y]>dis1[x]||dis1[y]>a[y])
            {
                dis1[y]=min(dis1[x],a[y]);
                if(!vis[y])Q.push((node){y,dis1[y]});
            }
        }
    }
}
void dijkstra2(int s)
{
    priority_queue<node,vector<node>,greater<node> >Q;
    Q.push((node){s,a[s]});
    while(Q.size())
    {
        int x=Q.top().pos;
        Q.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(int i=head2[x];i;i=e2[i].nxt)
        {
            int y=e2[i].to;
            if(dis2[y]<dis2[x]||dis2[y]<a[y])
            {
                dis2[y]=max(dis2[x],a[y]);
                if(!vis[y])Q.push((node){y,dis2[y]});
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
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    while(m--)
    {
        int u=read(),v=read(),w=read();
        add(u,v);
        if(w==2)add(v,u);
    }
    dijkstra1(1);
    memset(vis,false,sizeof(vis));
    dijkstra2(n);
    for(int i=1;i<=n;i++)ans=max(ans,dis2[i]-dis1[i]);
    printf("%d",ans);
    return 0;
}