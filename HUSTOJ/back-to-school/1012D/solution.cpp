#include<bits/stdc++.h>
#define L long long
using namespace std;
L n,a[1001],m,k;
L loc(L k)
{
    if(a[n]-a[k]<a[k])return 0;
    L l=k+1,r=n,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]-a[k]==a[k]) return -1;
        if(a[mid]-a[k]<a[k]) l=mid+1;
        if(a[mid]-a[k]>a[k]) r=mid-1;
    }
    return l;
}
int main()
{
    scanf("%lld%lld",&n,&a[1]);
    for(L i=2;i<=n;i++)a[i]=a[i-1]*1000000007%998244353;
    for(L i=2;i<=n;i++)a[i]+=a[i-1];
    scanf("%lld",&m);
    for(L i=1;i<=m;i++)
    {
        scanf("%lld",&k);
        L j=loc(k);
        if(j==0) printf("I was lost.");
        else if(j==-1) printf("Peace.");
        else printf("%lld",j-k);
        printf("\n");
    }
    return 0;
}