/*
User: shenyouran
Problem: 2197
Algorithm: Graph Theory, DFS
Language: C++
Record ID: 75882
Submit Time: 2020-11-14 14:46:16
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[251],flag;
vector<int>V[251];
void dfs(int s)
{
	vis[s]=true;
	for(int x:V[s])if(!vis[x])dfs(x);
}
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		V[x].push_back(y);
		V[y].push_back(x);
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