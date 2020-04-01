#include<bits/stdc++.h>
#pragma GCC optimize(2)
int dp[101][101],a[101],x,y;
int dfs(int pos,int stat,bool lead,bool limit)
{
    if(pos==-1)return stat>=32;
    if(!limit&&!lead&&dp[pos][stat]!=-1)return dp[pos][stat];
    int up=limit?a[pos]:1,ans=0;
    for(int i=0;i<=up;i++)ans+=lead&&!i?dfs(pos-1,stat,lead,limit&&i==a[pos]):dfs(pos-1,stat+(!i?1:-1),lead&&!i,limit&&i==a[pos]);
    if(!limit&&!lead)dp[pos][stat]=ans;
    return ans;
}
int solve(int x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x&1;
        x>>=1;
    }
    return dfs(pos-1,32,1,1);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&x,&y);
    printf("%d",solve(y)-solve(x-1));
}