#include<cstdio>
const int MAXN=3e5+5,MAXM=1e5+5;
int n,t,k,x,f,r,s,v[MAXM],i,j;
struct p
{
    int T,N;
}P[MAXN];
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&t,&k);
        for(j=1;j<=k;j++)
        {
            scanf("%d",&x);
            P[r].T=t;
            P[r].N=x;
            r++;
            v[x]++;
            if(v[x]==1)s++;
        }
        while(1)
        {
            if(t-P[f].T<86400)break;
            v[P[f].N]--;
            if(!v[P[f].N])s--;
            f++;
        }
        printf("%d\n",s);
    }
}
