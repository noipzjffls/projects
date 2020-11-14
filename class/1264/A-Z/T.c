/*
User: shenyouran
Problem: 2512
Algorithm: DFS
Language: C/C++
Record ID: 74529
Submit Time: 2020-10-17 14:43:00
*/
#include<stdio.h>
#include<stdbool.h>
int s=1<<30;
bool a[21],w[21];
void dfs(int k)
{
	if(k>20)
	{
		bool t[21],flag=true;
		int cnt=0;
		for(int i=1;i<=20;i++)t[i]=w[i];
		for(int i=1;i<=20;i++)
		{
			if(a[i])
			{
				t[i]^=true;
				if(i>1)t[i-1]^=true;
				if(i<20)t[i+1]^=true;
				cnt++;
			}
		}
		for(int i=1;i<=20;i++)
		{
			if(t[i])
			{
				flag=false;
				break;
			}
		}
		if(flag&&cnt<s)s=cnt;
		return;
	}
	a[k]=false;
	dfs(k+1);
	a[k]=true;
	dfs(k+1);
}
int main()
{
	for(int i=1;i<=20;i++)scanf("%d",&w[i]);
	dfs(1);
	printf("%d",s);
	return 0;
}