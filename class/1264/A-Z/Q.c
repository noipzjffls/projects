/*
User: shenyouran
Problem: 1358
Algorithm: Knapsack
Language: C/C++
Record ID: 74218
Submit Time: 2020-10-03 14:56:00
*/
#include<stdio.h>
#include<string.h>
int k,n,dp[2000001];
int min(int a,int b){return a<b?a:b;}
int main()
{
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	scanf("%d%d",&k,&n);
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		for(int j=x;j<=2e6;j++)if(dp[j-x]<k)dp[j]=min(dp[j],dp[j-x]+1);
	}
	for(int i=1;i<=2e6;i++)
	{
		if(dp[i]==0x3f3f3f3f)
		{
			printf("%d",i-1);
			return 0;
		}
	}
    return 0;
}