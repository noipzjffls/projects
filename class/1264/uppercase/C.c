/*
User: shenyouran
Problem: 1015
Algorithm: Knapsack
Language: C/C++
Record ID: 72952
Submit Time: 2020-09-12 14:11:42
*/
#include<stdio.h>
int max(int a,int b){return a>b?a:b;}
int v,n,w[31],dp[20001];
int main()
{
    scanf("%d%d",&v,&n);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)for(int j=v;j>=w[i];j--)dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
    printf("%d",v-dp[v]);
    return 0;
}