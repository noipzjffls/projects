#include<bits/stdc++.h>
using namespace std;
int n,a,b,k[201],ans[201];
void dfs(int cur,int step)
{
    if(step>ans[cur])return;
    ans[cur]=step;
    int dx[]={k[cur],-k[cur]};
    for(int i=0,nx;i<2;i++)
    {
        nx=cur+dx[i];
        if(nx>n||nx<1)continue;
        dfs(nx,step+1);
    }
}
int main()
{
    memset(ans,0x3f,sizeof(ans));
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)scanf("%d",&k[i]);
    dfs(a,0);
    if(ans[b]==0x3f3f3f3f)puts("-1");
    else printf("%d",ans[b]);
}