#include<bits/stdc++.h>
using namespace std;
long long n,p,k;
int main()
{
    scanf("%lld%lld%lld",&n,&p,&k);
    printf("%lld",p%n*(k%n)%n);
    return 0;
}