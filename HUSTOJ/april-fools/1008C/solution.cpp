#include<cstdio>
unsigned long long n,p,m,q;
int main()
{
    scanf("%llu%llu%llu%llu",&n,&p,&m,&q);
    if(m*p-q||m>n)
    {
        printf("0");
        return 0;
    }
    if(m==n)
    {
        printf("-1");
        return 0;
    }
    printf("%llu",n-m);
}