/*
User: shenyouran
Problem: 3177
Algorithm: Knapsack
Language: C/C++
Record ID: 73044
Submit Time: 2020-09-12 17:59:01
*/
#include<stdio.h>
#include<string.h>
int max(int a,int b){return a>b?a:b;}
int t,n,m,p[101][101],dp[10001];
int main()
{
    scanf("%d%d%d",&t,&n,&m);
    for(int i=1;i<=t;i++)for(int j=1;j<=n;j++)scanf("%d",&p[i][j]);
    for(int i=2;i<=t;i++)
    {
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=n;j++)
        {
            for(int k=p[i-1][j];k<=m;k++)
            {
                dp[k]=max(dp[k],dp[k-p[i-1][j]]-p[i-1][j]+p[i][j]);
            }
        }
        m+=dp[m];
    }
    printf("%d",m);
    return 0;
}