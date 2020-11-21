/*
User: shenyouran
Problem: 2218
Algorithm: Knapsack
Language: C/C++
Record ID: 73002
Submit Time: 2020-09-12 15:02:37
*/
#include<stdio.h>
int max(int a,int b){return a>b?a:b;}
int m,n,w[31],c[31],dp[201];
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&w[i],&c[i]);
    for(int i=1;i<=n;i++)
    {
    	for(int j=w[i];j<=m;j++)
    	{
    		dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
		}
	}
	printf("max=%d",dp[m]);
}