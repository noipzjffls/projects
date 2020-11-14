/*
User: shenyouran
Problem: 2325
Algorithm: Knapsack
Language: C/C++
Record ID: 72963
Submit Time: 2020-09-12 14:17:57
*/
#include<stdio.h>
int max(int a,int b){return a>b?a:b;}
int h,n,dp[45001],s[501];
int main()
{
	scanf("%d%d",&h,&n);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=h;j>=s[i];j--)
		{
			dp[j]=max(dp[j],dp[j-s[i]]+s[i]);
		}
	}
	printf("%d",dp[h]);
}