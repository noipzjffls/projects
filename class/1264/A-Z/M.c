/*
User: shenyouran
Problem: 1104
Algorithm: Knapsack
Language: C/C++
Record ID: 74161
Submit Time: 2020-10-03 13:52:32
*/
#include<stdio.h>
const int mod=1e6+7;
int n,m,dp[101]={1},a[101];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)for(int j=m;j>=0;j--)for(int k=1;k<=j&&k<=a[i];k++)dp[j]=(dp[j]+dp[j-k])%mod;
	printf("%d",dp[m]);
	return 0;
}