/*
User: shenyouran
Problem: 2306
Algorithm: Knapsack
Language: C/C++
Record ID: 73032
Submit Time: 2020-09-12 15:37:03
*/
#include<stdio.h>
#include<string.h>
int max(int a,int b){return a>b?a:b;}
int s,d,m,p[51][11],dp[500001];
int main()
{
    scanf("%d%d%d",&s,&d,&m);
    for(int i=1;i<=s;i++)for(int j=1;j<=d;j++)scanf("%d",&p[i][j]);
    for(int i=2;i<=d;i++)
    {
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=s;j++)
        {
            for(int k=p[j][i-1];k<=m;k++)
            {
                dp[k]=max(dp[k],dp[k-p[j][i-1]]-p[j][i-1]+p[j][i]);
            }
        }
        m+=dp[m];
    }
    printf("%d",m);
    return 0;
}