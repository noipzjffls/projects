/*
User: shenyouran
Problem: 1339
Algorithm: Knapsack
Language: C/C++
Record ID: 74191
Submit Time: 2020-10-03 14:24:11
*/
#include<stdio.h>
int n,m;
long long dp[391]={1};
int main()
{
    scanf("%d",&n);
    m=n*(n+1)>>1;
    if(m&1)
    {
        putchar('0');
        return 0;
    }
    m>>=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=i;j--)
        {
            dp[j]+=dp[j-i];
        }
    }
    printf("%lld",dp[m]>>1LL); 
    return 0;
}