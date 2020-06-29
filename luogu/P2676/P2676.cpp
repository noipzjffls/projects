#include<bits/stdc++.h>
using namespace std;
int n,b,h[20001],tot[20001];
bool cmp(int x,int y)
{
    return x>y;
}
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
    b=read();
    for(int i=1;i<=n;i++)h[i]=read();
    sort(h+1,h+n+1,cmp);
    for(int i=1;i<=n;i++)tot[i]=tot[i-1]+h[i];
    printf("%ld",lower_bound(tot+1,tot+n+1,b)-tot);
    return 0;
}