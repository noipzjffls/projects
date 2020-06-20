#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],b[1000005];
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
    k=read();
    while(k--)
    {
        int u=read(),v=read();
        a[u]++;
        a[v+1]--;
    }
    for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
    sort(b+1,b+n+1);
    printf("%d",b[(n>>1)+1]);
    return 0;
}