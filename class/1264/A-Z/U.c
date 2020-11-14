/*
User: shenyouran
Problem: 1608
Algorithm: DFS
Language: C/C++
Record ID: 74531
Submit Time: 2020-10-17 14:58:32
*/
#include<stdio.h>
#include<stdbool.h>
int n,s,a[51];
bool b[51];
void dfs(int k)
{
	if(k>n)
	{
		s++;
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		putchar('\n');
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i])continue;
		a[k]=i;
		b[i]=true;
		dfs(k+1);
		b[i]=false;
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	printf("Total=%d",s);
	return 0;
}