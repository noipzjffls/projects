/*
User: shenyouran
Problem: 2565
Algorithm: Spfa
Time Complexity: O(kp + p + c), for which k is a constant that meets k <= f
Storage Complexity: O(f + p + c)
*/
#include<bits/stdc++.h>
using namespace std;
int f,p,c,m,cnt,s,dis[501],head[501],ans[101];
bool vis[501];
struct edge
{
	int nxt,to,w;
}e[2001];
void add(int u,int v,int w)
{
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	e[cnt].w=w;
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
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				if(!vis[v])Q.push(v);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&f,&p,&c,&m);
	for(int i=1,u,v,w;i<=p;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	spfa(1);
	for(int i=1,x;i<=c;++i)
	{
		scanf("%d",&x);
		if(dis[x]<=m)ans[++s]=i;
	}
	printf("%d\n",s);
	for(int i=1;i<=s;++i)printf("%d\n",ans[i]);
	return 0;
}