/*
User: shenyouran
Problem: 3289
Algorithm: Knapsack
Language: C/C++
Record ID: 73339
Submit Time: 2020-09-19 15:36:51
*/
#include<stdio.h>
#include<string.h>
int a[11],dp[1001],m;
int min(int a,int b){return a<b?a:b;}
int main()
{
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=10;i++)scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=10;i++)for(int j=i;j<=m;j++)dp[j]=min(dp[j],dp[j-i]+a[i]);
    printf("%d",dp[m]);
    return 0;
}