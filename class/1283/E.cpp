/*
User: shenyouran
Problem: 2648
Algorithm: Spfa
Time Complexity: O(kc + c + p), for which k is a constant that meets k <= c
Storage Complexity: O(c + p)
*/
#include<bits/stdc++.h>
using namespace std;
int c,p,cnt,ans,dis[1001],head[1001];
bool vis[1001];
struct edge
{
	int nxt,to;
}e[20001];
void add(int u,int v)
{
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
void spfa(int s)
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	queue<int>Q;
	Q.push(s);
	vis[s]=true;
	while(Q.size())
	{
		int u=Q.front();
		Q.pop();
		vis[u]=false;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				if(!vis[v])
				{
				    vis[v]=true;
				    Q.push(v);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d",&c,&p);
	while(p--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	spfa(1);
	for(int i=2;i<=c;++i)ans=max(ans,dis[i]);
	printf("%d",ans);
	return 0;
}