#include<cstdio>
#include<cmath>
long long a,b,c;
int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("%lld",(long long)(4*(sqrt(a*b*c)/a+sqrt(a*b*c)/b+sqrt(a*b*c)/c)));
}