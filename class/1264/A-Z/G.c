/*
User: shenyouran
Problem: 1354
Algorithm: Knapsack
Language: C/C++
Record ID: 73009
Submit Time: 2020-09-12 15:04:53
*/
#include<stdio.h>
int max(int a,int b){return a>b?a:b;}
int m,n,w[10001],c[10001],dp[10001];
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&c[i],&w[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=w[i];j<=m;j++)
        {
            dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
        }
    }
    printf("%d",dp[m]);
}