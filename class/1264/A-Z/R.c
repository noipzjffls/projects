/*
User: shenyouran
Problem: 1606
Algorithm: DFS
Language: C/C++
Record ID: 74494
Submit Time: 2020-10-17 13:35:15
*/
#include<stdio.h>
int n,a[6];
void dfs(int k)
{
	if(k>n)
	{
		for(int i=1;i<=n;i++)putchar(a[i]+48);
		putchar(10);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		a[k]=i;
		dfs(k+1);
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}