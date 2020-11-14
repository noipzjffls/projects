/*
User: shenyouran
Problem: 3013
Algorithm: Knapsack, Binary
Language: C/C++
Record ID: 74269
Submit Time: 2020-10-05 17:14:24
*/
#include<stdio.h>
int n,m,dp[6000];
int max(int x,int y){return x>y?x:y;}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,a,b,c,p,v;i<=n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        for(int k=1;k<c;c-=k,k<<=1)
        {
            p=a*k,v=b*k;
            for(int j=m;j>=p;j--)dp[j]=max(dp[j],dp[j-p]+v);
        }
        if(c)
        {
            p=a*c,v=b*c;
            for(int j=m;j>=p;j--)dp[j]=max(dp[j],dp[j-p]+v);
        }
    }
    printf("%d",dp[m]);
    return 0;
}