/*
User: shenyouran
Problem: 1046
Algorithm: Knapsack
Language: C/C++
Record ID: 72948
Submit Time: 2020-09-12 14:07:35
*/
#include<stdio.h>
int max(int a,int b){return a>b?a:b;}
int m,n,w[101],c[101],dp[1001];
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&w[i],&c[i]);
    for(int i=1;i<=n;i++)for(int j=m;j>=w[i];j--)dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
    printf("%d",dp[m]);
    return 0;
}