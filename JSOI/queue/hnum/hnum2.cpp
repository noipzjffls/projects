#include<cstdio>
int n,i,j,f[4]={1,1,1,1},m[]={2,3,5,7};
long long h[100001],M;
int main()
{
    scanf("%d",&n);
    h[1]=1;
    for(i=2;i<=n;i++)
    {
        M=h[f[0]]*m[0];
        for(j=1;j<4;j++)if(h[f[j]]*m[j]<M)M=h[f[j]]*m[j];
        h[i]=M;
        for(j=0;j<4;j++)if(M==h[f[j]]*m[j])f[j]++;
    }
    printf("%lld",h[n]);
}
