#include<bits/stdc++.h>
int n,m,p,k,x,a[1000001];
std::map<unsigned,int>r;
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
    n=read(),m=read(),p=read();
    while(n--)
    {
        k=read();
        while(k--)r[read()]++;
    }
    for(int i=1;i<=m;i++)if(r[i]==p)a[++x]=i;
    printf("%d\n",x);
    for(int i=1;i<=x;i++)printf("%d ",a[i]);
    return 0;
}