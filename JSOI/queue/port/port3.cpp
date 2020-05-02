#include<cstdio>
#include<queue>
const int MAXN=1e5+5;
int n,t,k,x,s,v[MAXN],i,j;
std::queue<int>PT,PN;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&t,&k);
        for(j=1;j<=k;j++)
        {
            scanf("%d",&x);
            PT.push(t);
            PN.push(x);
            v[x]++;
            if(v[x]==1)s++;
        }
        while(1)
        {
            if(t-PT.front()<86400)break;
            v[PN.front()]--;
            if(!v[PN.front()])s--;
            PT.pop();
            PN.pop();
        }
        printf("%d\n",s);
    }
}
