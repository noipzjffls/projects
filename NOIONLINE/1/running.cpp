#include<cstdio>
int n,p,i,j;
long long f[100001]={1};
int main()
{
    freopen("running.in","r",stdin);
    freopen("running.out","w",stdout);
    scanf("%d%d",&n,&p);
    for(i=1;i<=n;i++)for(j=i;j<=n;j++)f[j]=(f[j]+f[j-i])%p;
    printf("%lld",f[n]%p);
    return 0;
}
