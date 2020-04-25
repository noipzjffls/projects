#include<cstdio>
int n,m,k,a[2501][2501],M;
bool b[2501][2501];
long long C=9e15,c=9e15;
void dfs(int city,int magic,long long cost,bool flag)
{
    if(city==n&&flag)
    {
        if(cost<C)
        {
            C=cost;
            M=magic;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==city||!b[city][i])continue;
        if(magic)dfs(i,magic-1,cost-a[city][i],1);
        dfs(i,magic,cost+a[city][i],1);
    }
}
bool find_circle(int city,bool flag)
{
    if(city==n&&flag)return 1;
    for(int i=1;i<=n;i++)
    {
        if(i==city||!b[city][i])continue;
        return find_circle(i,1);
    }
    return 0;
}
int main()
{
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    while(m--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        b[x][y]=1;
        a[x][y]=z;
    }
    dfs(1,k,0,1);
    if(!find_circle(n,0))printf("%lld",C);
    else
    {
        dfs(n,M,C,0);
        printf("%lld",C);
    }
    return 0;
}
