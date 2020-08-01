#include<stdio.h>
int n,m,p1,s1,s2,ans,c[100001];
long long a,b,mins,start;
int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)c[i]=read();
    m=read(),p1=read(),s1=read(),s2=read();
    c[p1]+=s1;
    for(int i=1;i<m;i++)a+=(long long)(m-i)*c[i];
    for(int i=m+1;i<=n;i++)b+=(long long)(i-m)*c[i];
    ans=m;
    start=a-b;
    mins=llabs(start);
    for(int i=m-1;i;i--)
    {
        long long cur=llabs(start+(long long)(m-i)*s2);
        if(cur<=mins)
        {
            mins=cur;
            ans=i;
        }
    }
    for(int i=m+1;i<=n;i++)
    {
        long long cur=llabs(start-(long long)(i-m)*s2);
        if(cur<mins)
        {
            mins=cur;
            ans=i;
        }
    }
    printf("%d",ans);
    return 0;
}