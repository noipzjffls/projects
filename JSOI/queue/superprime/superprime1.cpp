#include<cstdio>
int n,i,x=1,a[1001]={0,2};
bool p(int n)
{
    if(n<2)return 0;
    for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
    return 1;
}
bool check(int x)
{
    while(x)
    {
        if(!p(x))return 0;
        x-=x%10;
        x/=10;
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(i=3;i<=n;i+=2)if(check(i))a[++x]=i;
    printf("%d\n",x);
    for(i=1;i<=x;i++)printf("%d\n",a[i]);
}
