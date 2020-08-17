#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
int n,m,prime[maxn];
bool vis[maxn];
void f()
{
    for(int i=2;i<=maxn;i++)
    {
        if(!vis[i])prime[++prime[0]]=i;
        for(int j=1;i*prime[j]<=maxn&&j<=prime[0];j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
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
    f();
    n=read(),m=read();
    while(n--)
    {
        int l=read(),r=read();
        if(l<1||r>m)
        {
            puts("Crossing the line");
            continue;
        }
        int x=lower_bound(prime+1,prime+prime[0]+1,l)-prime,y=upper_bound(prime+1,prime+prime[0]+1,r)-prime-1;
        if(!y||x==prime[0]+1)
        {
            puts("0");
            continue;
        }
        printf("%d\n",y-x+1);
    }
}