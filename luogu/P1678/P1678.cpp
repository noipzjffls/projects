#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001];
long long ans;
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
    m=read();
    n=read();
    for(int i=1;i<=m;i++)a[i]=read();
    sort(a+1,a+m+1);
    while(n--)
    {
        int x=read(),pos1=lower_bound(a+1,a+m+1,x)-a,pos2=pos1-1,cur=1<<30;
        if(pos1<=m)cur=min(cur,a[pos1]-x);
        if(pos2)cur=min(cur,x-a[pos2]);
        if(cur==1<<30)continue;
        ans+=cur;
    }
    printf("%lld",ans);
    return 0;
}