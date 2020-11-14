/*
User: shenyouran
Problem: 2197
Algorithm: Graph Theory, DFS
Language: C/C++
Record ID: 75865
Submit Time: 2020-11-14 13:59:10
*/
#include<stdio.h>
#include<stdbool.h>
int n,m;
bool f[251][251],vis[251],flag;
void dfs(int s)
{
	vis[s]=true;
	for(int i=1;i<=n;i++)
	{
		if(!f[s][i]||vis[i])continue;
		dfs(i);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		f[x][y]=f[y][x]=true;
	}
	dfs(1);
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			printf("%d\n",i);
			flag=true;
		}
	}
	if(!flag)puts("0");
	return 0;
}