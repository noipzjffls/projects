#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,len,a[100001];
bool check(ll dis)
{
    ll cnt=0;
    for(int i=1;i<n;i++)
    {
        if(a[i+1]-a[i]>dis)
        {
            cnt+=(a[i+1]-a[i])/dis;
            if((a[i+1]-a[i])%dis==0)cnt--;
        }
    }
    if(cnt<=k)return true;
    return false;
}
ll read()
{
    ll x=0;
    int f=1;
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
    scanf("%lld%lld%lld",&len,&n,&k);
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    ll l=1,r=len,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    printf("%lld",l);
}