#include<cstdio>
using namespace std;
int n,L,v,q,a[200001],mint,b[200001],c[200001];
int simulate(int dig)
{
    int time=0;
    for(int i=1;i<=dig;i++)time+=a[b[i]];
    return time+L;
}
void dfs(int k,int dig)
{
    if(k>dig)
    {
        int num=simulate(dig);
        if(num>mint)mint=num;
        return;
    }
    for(int i=b[k-1]+1;i<=n;i++)
    {
        b[k]=i;
        dfs(k+1,dig);
    }
}
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main()
{
    freopen("endless.in","r",stdin);
    freopen("endless.out","w",stdout);
    n=read();
    L=read();
    v=read();
    for(int i=1;i<=n;i++)a[i]=read();
    q=read();
    for(int j=1;j<=n;j++)
    {
        b[0]=0;
        dfs(1,j);
        c[j]=mint;
    }
    while(q--)
    {
        int x=read();
        if(L>v*x)
        {
            puts("0");
            continue;
        }
        bool flag=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i]>x*v)
            {
                printf("%d\n",i);
                flag=1;
                break;
            }
        }
        if(!flag)puts("-1");
    }
    return 0;
}