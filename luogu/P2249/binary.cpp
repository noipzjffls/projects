#include<bits/stdc++.h>
using namespace std;
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
int n,m,a[1000001];
int find(int x)
{
    int l=1,r=n,mid;
    while(l<r)
    {
        mid=l+((r-l)>>1);
        if(a[mid]>=x)r=mid;
        else l=mid+1;
    }
    return a[l]==x?l:-1;
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    while(m--)printf("%d ",find(read()));
    return 0;
}