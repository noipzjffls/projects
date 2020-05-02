#include<cstdio>
int n,i,j,l,t[100001],k[100001],ship[100001][300001],h[100001],s;
void set()
{
    for(int i=0;i<=1e5;i++)h[i]=0;
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&t[i],&k[i]);
        for(j=1;j<=k[i];j++)scanf("%d",&ship[i][j]);
    }
    for(i=1;i<=n;i++)
    {
        set();
        for(j=1;j<=i;j++)if(t[i]-t[j]<864e2)for(l=1;l<=k[j];l++)h[ship[j][l]]=1;
        for(j=1;j<=1e5;i++)s+=h[j];
        printf("%d\n",s);
    }
}
