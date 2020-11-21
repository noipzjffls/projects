/*
User: shenyouran
Problem: 1611
Algorithm: DFS
Language: C/C++
Record ID: 74537
Submit Time: 2020-10-17 15:03:51
*/
#include<stdio.h>
#include<stdbool.h>
int n,a[11];
bool b[11],ok;
bool check(int x)
{
	if(x<2)return false;
	for(int i=2;i*i<=x;i++)if(x%i==0)return false;
	return true;
}
void dfs(int k)
{
	if(k>n)
	{
		bool flag=true;
		for(int i=1;i<n;i++)
		{
			if(!check(a[i]+a[i+1]))
			{
				flag=false;
				break;
			}
		}
		if(!flag||!check(a[1]+a[n]))return;
		if(flag)
		{
			ok=true;
			for(int i=1;i<=n;i++)printf("%d ",a[i]);
			putchar('\n');
		}
		return;
	}
	for(int i=2;i<=n;i++)
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
	a[1]=1;
	b[1]=true;
	dfs(2);
	if(!ok)puts("No Solution");
	return 0;
}