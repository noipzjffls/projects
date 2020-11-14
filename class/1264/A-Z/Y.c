/*
User: shenyouran
Problem: 1336
Algorithm: DFS
Language: C/C++
Record ID: 74614
Submit Time: 2020-10-18 10:10:35
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int v,g,a[26],b[16][26],id[16];
bool f[16];
void dfs(int k,int x)
{
	if(k>x)
	{
		int c[26]={};
		for(int i=1;i<=x;i++)for(int j=1;j<=v;j++)c[j]+=b[id[i]][j];
		for(int i=1;i<=v;i++)if(a[i]>c[i])return;
		printf("%d ",x);
		for(int i=1;i<=x;i++)printf("%d ",id[i]);
		exit(0);
	}
	for(int i=id[k-1]+1;i<=g;i++)
	{
		if(f[i])continue;
		id[k]=i;
		f[i]=true;
		dfs(k+1,x);
		f[i]=false;
	}
}
int main()
{
	scanf("%d",&v);
	for(int i=1;i<=v;i++)scanf("%d",&a[i]);
	scanf("%d",&g);
	for(int i=1;i<=g;i++)for(int j=1;j<=v;j++)scanf("%d",&b[i][j]);
	for(int i=1;i<=g;i++,memset(id,0,sizeof(id)),memset(f,false,sizeof(f)))dfs(1,i);
	return 0;
}