#include<bits/stdc++.h>
using namespace std;
long long ans=1,b,m,p;
int main()
{
    scanf("%lld%lld%lld",&b,&m,&p);
    while(m>0)
    {
        if(m&1)ans=ans*b%p;
        b=b*b%p;
        m>>=1;
    }
    printf("%lld",ans%p);
}