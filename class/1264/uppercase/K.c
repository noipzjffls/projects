/*
User: shenyouran
Problem: 3245
Algorithm: Knapsack, Binary
Language: C/C++
Record ID: 73358
Submit Time: 2020-09-19 16:51:02
*/
#include<stdio.h>
int T;
int max(int a,int b){return a>b?a:b;}
int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
int main()
{
    T=read();
    while(T--)
    {
        int n=read(),W=read(),cnt=0,w[100001]={},v[100001]={},dp[10001]={},a[101]={},b[101]={},c[101]={};
        for(int i=1;i<=n;i++)
        {
            int x=read(),y=read(),p=10*(x-1)+y;
            a[p]=y;
            b[p]=x;
            c[p]++;
        }
        for(int i=1;i<101;i++)
        {
            for(int k=1;k<c[i];c[i]-=k,k<<=1)for(int j=W,w=a[i]*k,v=b[i]*k;j>=w;j--)dp[j]=max(dp[j],dp[j-w]+v);
            if(c[i])for(int j=W,w=a[i]*c[i],v=b[i]*c[i];j>=w;j--)dp[j]=max(dp[j],dp[j-w]+v);
        }
        printf("%d\n",dp[W]);
    }
    return 0;
}