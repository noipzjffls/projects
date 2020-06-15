#include<bits/stdc++.h>
using namespace std;
int n,m;
unordered_map<int,int>M;
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
    for(int i=1,x;i<=n;i++)
    {
        x=read();
        if(M[x])continue;
        M[x]=i;
    }
    while(m--)
    {
        int x=read();
        printf("%d ",!M[x]?-1:M[x]);
    }
    return 0;
}