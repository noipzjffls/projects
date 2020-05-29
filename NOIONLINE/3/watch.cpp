#include<bits/stdc++.h>
using namespace std;
int n,m,t;
bool flag,vis[201];
struct node
{
    int val,cnt;
}money[201];
bool cmp(node a,node b)
{
    return a.val<b.val;
}
void dfs(int remain)
{
    if(!remain)flag=true;
    if(flag)return;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=money[i].cnt;j++)
        {
            int cost=j*money[i].val;
            if(cost<=remain&&!vis[i])
            {
                vis[i]=true;
                dfs(remain-cost);
                vis[i]=false;
            }
        }
    }
}
int main()
{
    freopen("watch.in","r",stdin);
    freopen("watch.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",&money[i].val,&money[i].cnt);
    sort(money+1,money+n+1,cmp);
    while(m--)
    {
        scanf("%d",&t);
        if(!t)
        {
            puts("Yes");
            continue;
        }
        if(t<money[1].val)
        {
            puts("No");
            continue;
        }
        flag=false;
        for(int i=1;i<=n;i++)vis[i]=false;
        dfs(t);
        if(flag)puts("Yes");
        else puts("No");
    }
    return 0;
}