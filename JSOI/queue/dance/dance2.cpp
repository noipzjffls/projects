#include<cstdio>
const int MAXN=1e3;
int m,n,i,k,q1[MAXN],q2[MAXN],f1=1,f2=1,r1,r2;
int main()
{
    scanf("%d%d%d",&m,&n,&k);
    r1=m+1;
    r2=n+1;
    for(i=1;i<=m;i++)q1[i]=i;
    for(i=1;i<=n;i++)q2[i]=i;
    for(i=1;i<=k;i++)
    {
        printf("%d %d\n",q1[f1],q2[f2]);
        q1[r1++]=q1[f1++];
        q2[r2++]=q2[f2++];
        if(r1==MAXN)r1=1;
        if(r2==MAXN)r2=1;
        if(f1==MAXN)f1=1;
        if(f2==MAXN)f2=1;
    }
}
