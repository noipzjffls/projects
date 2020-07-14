#include<cstdio>
short n,g[1001][1001];
int cnt;
short check(short x,short y)
{
    for(short i=1,e1,e2;i<=n;i++)
    {
        if(i==x||i==y)continue;
        e1=g[x][i];
        e2=g[i][y];
        if(!e1||!e2)continue;
        if(e1==1&&e2==1)return -1;
    }
    return 1;
}
int main()
{
    scanf("%hd",&n);
    for(short i=1;i<n;i++)g[i][i+1]=1;
    if(n&1)g[1][n]=-1;
    else g[1][n]=1;
    for(short i=1;i<n-1;i++)g[i][i+2]=-1;
    if(!(n&1))g[1][n-1]=-1;
    for(short i=1;i<n;i++)
    {
        for(short j=i+1;j<=n;j++)
        {
            if(g[i][j])continue;
            g[i][j]=check(i,j);
        }
    }
    for(short i=1;i<n;i++)
    {
        for(short j=i+1;j<=n;j++)
        {
            cnt+=g[i][j]==1;
        }
    }
    printf("%d",cnt);
    return 0;
}