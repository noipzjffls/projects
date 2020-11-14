/*
User: shenyouran
Problem: 1345
Algorithm: Knapsack
Language: C/C++
Record ID: 74193
Submit Time: 2020-10-03 14:27:14
*/
#include<stdio.h>
int v,n;
long long dp[10001]={1};
int main()
{
    scanf("%d%d",&v,&n);
    for(int i=1,x;i<=v;i++)
    {
        scanf("%d",&x);
        for(int j=n;j>=x;j--)
        {
            for(int k=1;k*x<=j;k++)
            {
                dp[j]+=dp[j-k*x];
            }
        }
    }
    printf("%lld",dp[n]);
    return 0;
}