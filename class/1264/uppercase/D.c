/*
User: shenyouran
Problem: 2404
Algorithm: Knapsack
Language: C/C++
Record ID: 72957
Submit Time: 2020-09-12 14:14:58
*/
#include<stdio.h>
int max(int a,int b){return a>b?a:b;}
int n,m,dp[12881],c[3403],w[3403];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&c[i],&w[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=c[i];j--)
		{
			dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
		}
	}
	printf("%d",dp[m]);
}