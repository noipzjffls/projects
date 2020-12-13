#include<stdio.h>
int n,m,cn=1,a[100001];
long long mod;
struct SegmentTree
{
    int ls,rs,l,r;
    long long sum,add,mul;
}t[200001];
void push_up(int p){t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;}
void push_down(int p)
{
    int ls=t[p].ls,rs=t[p].rs;
    t[ls].sum=(t[ls].sum*t[p].mul+(t[ls].r-t[ls].l+1)*t[p].add)%mod;
    t[rs].sum=(t[rs].sum*t[p].mul+(t[rs].r-t[rs].l+1)*t[p].add)%mod;
    t[ls].mul=t[ls].mul*t[p].mul%mod;
    t[rs].mul=t[rs].mul*t[p].mul%mod;
    t[ls].add=(t[ls].add*t[p].mul+t[p].add)%mod;
    t[rs].add=(t[rs].add*t[p].mul+t[p].add)%mod;
    t[p].mul=1;
    t[p].add=0;
}
void build(int p,int l,int r)
{
    t[p].l=l,t[p].r=r,t[p].mul=1;
    if(l==r)
    {
        t[p].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    t[p].ls=++cn;
    build(cn,l,mid);
    t[p].rs=++cn;
    build(cn,mid+1,r);
    push_up(p);
}
void add(int p,int l,int r,int k)
{
    if(l<=t[p].l&&t[p].r<=r)
    {
        t[p].sum=(t[p].sum+1LL*(t[p].r-t[p].l+1)*k)%mod;
        t[p].add=(t[p].add+k)%mod;
        return;
    }
    push_down(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(l<=mid)add(t[p].ls,l,r,k);
    if(r>mid)add(t[p].rs,l,r,k);
    push_up(p);
}
void mul(int p,int l,int r,int k)
{
    if(l<=t[p].l&&t[p].r<=r)
    {
        t[p].sum=t[p].sum*k%mod;
        t[p].add=t[p].add*k%mod;
        t[p].mul=t[p].mul*k%mod;
        return;
    }
    push_down(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(l<=mid)mul(t[p].ls,l,r,k);
    if(r>mid)mul(t[p].rs,l,r,k);
    push_up(p);
}
long long query(int p,int l,int r)
{
    if(l<=t[p].l&&t[p].r<=r)return t[p].sum;
    push_down(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(l>mid)return query(t[p].rs,l,r)%mod;
    if(r<=mid)return query(t[p].ls,l,r)%mod;
    return (query(t[p].ls,l,r)+query(t[p].rs,l,r))%mod;
}
int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
int main()
{
    n=read(),m=read(),mod=read();
    for(int i=1;i<=n;i++)a[i]=read();
    build(1,1,n);
    while(m--)
    {
        int op=read(),x=read(),y=read(),k;
        if(op==1)
        {
            k=read();
            mul(1,x,y,k);
        }
        else if(op==2)
        {
            k=read();
            add(1,x,y,k);
        }
        else printf("%lld\n",query(1,x,y));
    }
    return 0;
}