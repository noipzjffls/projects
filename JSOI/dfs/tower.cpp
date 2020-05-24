#include<cstdio>
short r,a[21][21],dp[21][21],maxn;
short max(short x,short y)
{
    return x>y?x:y;
}
int main()
{
    scanf("%hd",&r);
    for(short i=1;i<=r;i++)
    {
        for(short j=1;j<=i;j++)
        {
            scanf("%hd",&a[i][j]);
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
        }
    }
    for(short i=1;i<=r;i++)maxn=max(dp[r][i],maxn);
    printf("%hd",maxn);
}