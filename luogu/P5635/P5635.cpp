#include<bits/stdc++.h>
using namespace std;
short x,y,m,t,mod,f[10001][10001];
short dfs(short x,short y)
{
    if(f[x][y]==-1)return 3;
    if(f[x][y])return f[x][y];
    f[x][y]=-1;
    if(!x)return f[x][y]=1;
    if(!y)return f[x][y]=2;
    return f[x][y]=dfs((x+y)%mod,((x+y)%mod+y)%mod);
}
int main()
{
    scanf("%hd%hd",&t,&mod);
    while(t--)
    {
        scanf("%hd%hd",&x,&y);
        short ans=dfs(x,y);
        if(ans==3)puts("error");
        else printf("%hd\n",ans);
    }
    return 0;
}