#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int n,a,b,c,i,j,k,s;
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
int main()
{
    n=read();
    a=read();
    b=read();
    c=read();
    if(0.5*a+b+c*2<n)
    {
        printf("0");
        return 0;
    }
    for(i=0;i<=n*2&&i<=a;i+=2)for(j=0;j<=n&&j<=b;j++)for(k=0;k<=n/2&&k<=c;k++)if(i/2+j+2*k==n)s++;
    printf("%d",s);
}