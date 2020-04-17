#include<cstdio>
int x,n;
int main()
{
    scanf("%d",&x);
    while(x)
    {
        n+=x&1;
        x>>=1;
    }
    printf("%d",n);
}