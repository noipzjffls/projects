#include<bits/stdc++.h>
using namespace std;
int n,k,a[21],x[21],ans;
bool p(int x)
{
    if(x<2)return false;
    for(int i=2;i*i<=x;i++)if(x%i==0)return false;
    return true;
}
void dfs(int kk)
{
    if(kk>k)
    {
        int sum=0;
        for(int i=1;i<=k;i++)sum+=x[a[i]];
        if(p(sum))ans++;
        return;
    }
    for(int i=a[kk-1]+1;i<=n;i++)
    {
        a[kk]=i;
        dfs(kk+1);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&x[i]);
    dfs(1);
    printf("%d",ans);
    return 0;
}