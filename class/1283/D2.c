/*
User: shenyouran
Problem: 2565
Algorithm: Bellman Ford
Time Complexity: O(f^2 + p + c)
Storage Complexity: O(f + p + c)
*/
#include<stdio.h>
#include<string.h>
int f,p,c,m,cnt,s,dis[501],ans[101];
struct edge
{
	int u,v,w;
}e[1001];
void bellman_ford(int s)
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	for(int i=1;i<f;++i)
	{
		for(int j=1;j<=p;++j)
		{
			int u=e[j].u,v=e[j].v,w=e[j].w;
			if(dis[u]+w<dis[v])dis[v]=dis[u]+w;
			if(dis[v]+w<dis[u])dis[u]=dis[v]+w;
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&f,&p,&c,&m);
	for(int i=1;i<=p;++i)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	bellman_ford(1);
	for(int i=1,x;i<=c;++i)
	{
		scanf("%d",&x);
		if(dis[x]<=m)ans[++s]=i;
	}
	printf("%d\n",s);
	for(int i=1;i<=s;++i)printf("%d\n",ans[i]);
	return 0;
}