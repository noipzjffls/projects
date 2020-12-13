#include<stdio.h>
int n,m,cn=1,a[1000001];
struct SegmentTree
{
    int ls,rs,l,r;
    long long sum,tag;
}t[200001];
void push_up(int p){t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;}
void push_down(int p)
{
    if(t[p].tag)
    {
        int ls=t[p].ls,rs=t[p].rs;
        t[ls].sum+=(t[ls].r-t[ls].l+1)*t[p].tag;
        t[rs].sum+=(t[rs].r-t[rs].l+1)*t[p].tag;
        t[ls].tag+=t[p].tag;
        t[rs].tag+=t[p].tag;
        t[p].tag=0;
    }
}
void build(int p,int l,int r)
{
    t[p].l=l,t[p].r=r;
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
void update(int p,int l,int r,int k)
{
    if(l<=t[p].l&&t[p].r<=r)
    {
        t[p].sum+=1LL*(t[p].r-t[p].l+1)*k;
        t[p].tag+=k;
        return;
    }
    push_down(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(l<=mid)update(t[p].ls,l,r,k);
    if(r>mid)update(t[p].rs,l,r,k);
    push_up(p);
}
long long query(int p,int l,int r)
{
    if(l<=t[p].l&&t[p].r<=r)return t[p].sum;
    push_down(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(l>mid)return query(t[p].rs,l,r);
    if(r<=mid)return query(t[p].ls,l,r);
    return query(t[p].rs,l,r)+query(t[p].ls,l,r);
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
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    build(1,1,n);
    while(m--)
    {
        int op=read(),x=read(),y=read(),k;
        if(op==1)
        {
            k=read();
            update(1,x,y,k);
        }
        else printf("%lld\n",query(1,x,y));
    }
    return 0;
}