#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,x;
int cnt(ll x)
{
    int num=0;
    while(x)
    {
        if(x&1)num++;
        x>>=1;
    }
    return num;
}
ll find(ll num)
{
    ll s=1,i=0;
    for(;;i++)
    {
        if(s>=num)break;
        s<<=1;
        s++;
    }
    return i;
}
void cal(ll lbound,ll rbound)
{
    int y=0;
    for(ll i=lbound;i<=rbound;i++)
    {
        int x=cnt(i);
        if(x>y)y=x;
    }
    printf("%d",y);
}
bool check(ll n)
{
    ll s=1;
    for(int i=0;;i++)
    {
        if(s>n)return 0;
        if(s==n)return 1;
        s<<=1;
        s++;
    }
}
int main()
{
    scanf("%lld%lld",&a,&b);
    x=(1<<find(b))-1;
    if(check(b))
    {
        x<<=1;
        x++;
    }
    if(x>=a)printf("%d",cnt(x));
    else cal(a,b);
}