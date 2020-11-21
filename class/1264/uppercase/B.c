/*
User: shenyouran
Problem: 1053
Algorithm: Knapsack
Language: C/C++
Record ID: 72949
Submit Time: 2020-09-12 14:09:48
*/
#include<stdio.h>
int max(int a,int b){return a>b?a:b;}
int m,n,w[25],c[25],dp[30000];
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&w[i],&c[i]);
    for(int i=1;i<=n;i++)for(int j=m;j>=w[i];j--)dp[j]=max(dp[j],dp[j-w[i]]+w[i]*c[i]);
    printf("%d",dp[m]);
    return 0;
}