/*
User: shenyouran
Problem: 1021
Algorithm: DFS
Language: C/C++
Record ID: 74853
Submit Time: 2020-10-24 13:51:21
*/
#include<stdio.h>
#include<stdbool.h>
int n,r,ans,a[21],x[21];
bool check(int x)
{
	if(x<2)return false;
	if(x==2)return true;
	if(x%2==0)return false;
	for(int i=3;i*i<=x;i+=2)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
void dfs(int k)
{
	if(k>r)
	{
		int s=0;
		for(int i=1;i<=r;i++)s+=x[a[i]];
		ans+=check(s);
		return;
	}
	for(int i=a[k-1]+1;i<=n;i++)
	{
		a[k]=i;
		dfs(k+1);
	}
}
int main()
{
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++)scanf("%d",&x[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}