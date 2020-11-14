/*
User: shenyouran
Problem: 2197
Algorithm: Graph Theory, DFS
Language: C/C++
Record ID: 75872
Submit Time: 2020-11-14 14:25:42
*/
#include<stdio.h>
#include<stdbool.h>
int n,m,cnt,head[251];
bool vis[251];
struct node
{
	int nxt,to;
}e[62501];
void add(int u,int v)
{
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
void dfs(int s)
{
	if(vis[s])return;
	vis[s]=true;
	for(int i=head[s];i;i=e[i].nxt)if(!vis[e[i].to])dfs(e[i].to);
}
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1);
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			printf("%d\n",i);
			vis[0]=true;
		}
	}
	if(!vis[0])puts("0");
	return 0;
}