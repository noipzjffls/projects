#include<cstdio>
long long n,last,s;
int main()
{
    scanf("%lld",&n);
    for(int i=1;;i++)
    {
        last=s;
        s+=i;
        if(s>=n)break;
    }
    printf("%lld",n-last);
}