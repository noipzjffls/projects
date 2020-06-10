#include<bits/stdc++.h>
using namespace std;
int n,mine[21],ans,path[21],route[21],len;
bool connect[21][21];
void dfs(int pos,int cnt,int depth)
{
    path[depth]=pos;
    cnt+=mine[pos];
    if(cnt>ans)
    {
        ans=cnt;
        len=depth;
        for(int i=1;i<=depth;i++)route[i]=path[i];
    }
    for(int i=pos+1;i<=n;i++)
    {
        if(!connect[pos][i])continue;
        dfs(i,cnt,depth+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&mine[i]);
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cin>>connect[i][j];
        }
    }
    for(int i=1;i<n;i++)dfs(i,0,1);
    for(int i=1;i<=len;i++)printf("%d ",route[i]);
    printf("\n%d",ans);
    return 0;
}