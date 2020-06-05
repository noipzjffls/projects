#include<bits/stdc++.h>
using namespace std;
int n,c;
long long ans,a[200001];
int find1(int x,int l,int r)
{
    int mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(a[mid]>=x)r=mid-1;
        else l=mid+1;
    }
    return l;
}
int find2(int x,int l,int r)
{
    int mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(a[mid]>x)r=mid-1;
        else l=mid+1;
    }
    return l;
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
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)ans+=find2(a[i]+c,i+1,n)-find1(a[i]+c,i+1,n);
    printf("%lld",ans);
    return 0;
}