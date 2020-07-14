#include<bits/stdc++.h>
using namespace std;
int n,k,l,r,a[50001];
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
bool check(int x)
{
    int cur=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(cur>=a[i])continue;
        cnt++;
        cur=a[i]+(x<<1);
    }
    return cnt<=k;
}
int main()
{
    n=read();
    k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    r=a[n];
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    printf("%d",l);
    return 0;
}