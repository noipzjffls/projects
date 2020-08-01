#include<bits/stdc++.h>
using namespace std;
int n,m,p1,s1,s2,ans,c[100001];
long long a,b,mins,start;
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
    for(int i=1;i<=n;i++)c[i]=read();
    m=read(),p1=read(),s1=read(),s2=read();
    c[p1]+=s1;
    for(int i=1;i<m;i++)a+=1LL*(m-i)*c[i];
    for(int i=m+1;i<=n;i++)b+=1LL*(i-m)*c[i];
    ans=m;
    start=a-b;
    mins=llabs(start);
    for(int i=1;i<m;i++)
    {
        long long cur=llabs(start+1LL*(m-i)*s2);
        if(cur<mins)
        {
            mins=cur;
            ans=i;
        }
    }
    for(int i=m+1;i<=n;i++)
    {
        long long cur=llabs(start-1LL*(i-m)*s2);
        if(cur<mins)
        {
            mins=cur;
            ans=i;
        }
    }
    printf("%d",ans);
    return 0;
}