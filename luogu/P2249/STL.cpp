#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001];
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
    m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    while(m--)
    {
        int temp=read(),pos=lower_bound(a+1,a+n+1,temp)-a;
        if(pos==n+1)
        {
            printf("-1 ");
            continue;
        }
        if(a[pos]!=temp)
        {
            printf("-1 ");
            continue;
        }
        printf("%d ",pos);
    }
    return 0;
}