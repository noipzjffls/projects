/*
User: shenyouran
Problem: 2224
Algorithm: Knapsack
Language: C/C++
Record ID: 74201
Submit Time: 2020-10-03 14:45:28
*/
#include<stdio.h>
#include<stdbool.h>
bool dp[1001]={true};
int ans,b[1001],p;
const int a[]={1,2,3,5,10,20};
int main()
{
    for(int i=0,x;i<6;i++)
    {
        scanf("%d",&x);
        while(x--)b[++p]=a[i];
    }
    for(int i=1;i<=p;i++)
    {
        for(int j=1000;j>=b[i];j--)
        {
            dp[j]|=dp[j-b[i]];
        }
    }
    for(int i=1;i<=1000;i++)if(dp[i])ans++;
    printf("Total=%d",ans);
    return 0;
}