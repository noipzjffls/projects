/*
User: shenyouran
Problem: 2235
Algorithm: DFS
Language: C/C++
Record ID: 74913
Submit Time: 2020-10-24 15:08:00
*/
#include<stdio.h>
int t,n,m,s,ans,w[21],a[21];
int min(int a,int b){return a<b?a:b;}
int abs(int a){return a>0?a:-a;}
void dfs(int k)
{
    if(k>m)
    {
        int t=0;
        for(int i=1;i<=m;i++)t+=w[a[i]];
        ans=min(ans,abs((t<<1)-s));
        return;
    }
    for(int i=a[k-1]+1;i<=n;i++)
    {
        a[k]=i;
        dfs(k+1);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        m=n>>1;
        s=0;
        ans=1<<30;
        for(int i=1;i<=n;i++)scanf("%d",&w[i]),s+=w[i];
        dfs(1);
        printf("%d\n",ans); 
    }
    return 0;
}