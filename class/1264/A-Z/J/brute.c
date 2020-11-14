/*
User: shenyouran
Problem: 3013
Algorithm: Knapsack
Language: C/C++
Record ID: 73279
Submit Time: 2020-09-19 14:11:48
*/
#include<stdio.h>
int n,m,p[501],v[501],s[501],dp[6000];
int max(int a,int b){return a>b?a:b;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&p[i],&v[i],&s[i]);
	for(int i=1;i<=n;i++)for(int j=m;j;j--)for(int k=1;k<=s[i]&&k*p[i]<=j;k++)dp[j]=max(dp[j],dp[j-k*p[i]]+k*v[i]);
	printf("%d",dp[m]);
	return 0;
}