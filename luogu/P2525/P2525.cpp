#include<bits/stdc++.h>
using namespace std;
int n,a[10],s[10],t[10],last[10];
bool flag[10];
bool same(int a[],int b[])
{
    for(int i=1;i<=n;i++)if(a[i]!=b[i])return false;
    return true;
}
void dfs(int k)
{
    if(k>n)
    {
        int cur[10];
        for(int i=1;i<=n;i++)cur[i]=s[a[i]];
        if(same(cur,t))
        {
            for(int i=1;i<=n;i++)printf("%d ",last[i]);
            exit(0);
        }
        for(int i=1;i<=n;i++)last[i]=cur[i];
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!flag[i])
        {
            a[k]=i;
            flag[i]=true;
            dfs(k+1);
            flag[i]=false;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        t[i]=last[i]=s[i];
    }
    sort(s+1,s+n+1);
    if(same(s,t))
    {
        cout<<"ERROR";
        return 0;
    }
    dfs(1);
    return 0;
}