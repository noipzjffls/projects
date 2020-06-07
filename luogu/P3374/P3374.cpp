#include<bits/stdc++.h>
#define lowbit(x) x&-x
using namespace std;
int n,m,a[500001],c[500001];
void update(int x,int d)
{
    while(x<=n)
    {
        c[x]+=d;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int s=0;
    while(x>0)
    {
        s+=c[x];
        x-=lowbit(x);
    }
    return s;
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
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        update(i,a[i]);
    }
    while(m--)
    {
        int opt=read(),u=read(),v=read();
        if(opt==1)update(u,v);
        else cout<<sum(v)-sum(u-1)<<endl;
    }
    return 0;
}