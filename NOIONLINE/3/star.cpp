#include<cstdio>
int n,m,dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1},cnt,temp,maxn,minn=1<<30,star[100001],maxs;
char maps[1501][1501];
void dfs(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&ny>0&&nx<=n&&ny<=m&&maps[nx][ny]=='*')
        {
            temp++;
            maps[nx][ny]='.';
            dfs(nx,ny);
        }
    }
}
int main()
{
    freopen("star.in","r",stdin);
    freopen("star.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        getchar();
        for(int j=1;j<=m;j++)maps[i][j]=getchar();
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(maps[i][j]=='*')
            {
                temp=0;
                dfs(i,j);
                star[temp]++;
                if(temp>maxn)maxn=temp;
                if(temp<minn)minn=temp;
            }
        }
    }
    for(int i=minn;i<=maxn;i++)
    {
        if(!star[i])continue;
        cnt++;
        long long x=star[i]*i;
        if(x>maxs)maxs=x;
    }
    printf("%d %d",cnt,maxs);
}