#include<cstdio>
const int maxn=101;
int n,m,s,maxs,dx[]={-1,0,0,1},dy[]={0,-1,1,0};
bool rect[maxn][maxn],vis[maxn][maxn];
void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a>0&&b>0&&a<=n&&b<=m&&rect[a][b]&&!vis[a][b])
        {
            vis[a][b]=1;
            s++;
            dfs(a,b);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&rect[i][j]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<maxn;k++)for(int K=1;K<maxn;K++)vis[k][K]=0;
            if(!rect[i][j])continue;
            dfs(i,j);
            if(s>maxs)maxs=s;
            s=0;
        }
    }
    printf("%d",maxs);
}
