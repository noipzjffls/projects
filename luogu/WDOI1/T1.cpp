#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long
using namespace std;
int n,k,pos;
const int maxn=1e7;
ll t;
struct node
{
    ll num;
    int cnt;
}q[maxn];
ll read()
{
    int w=1;
    char c;
    ll ret;
    while((c=getchar())>'9'||c< '0')
    w=(c=='-'?-1:1); ret=c^'0';
    while((c=getchar())>='0'&&c<='9')
    ret=(ret<<3)+(ret<<1)+(c^'0');
    return ret*w;
}
void find(ll x)
{
    for(int i=1;i<=pos;i++)
    {
        if(q[i].num==x)
        {
            q[i].cnt++;
            return;
        }
    }
    q[++pos].num=x;
    q[pos].cnt=1;
}
int main()
{
    n=read();
    k=read();
    while(n--)find(read());
    for(int i=1;i<=pos;i++)
    {
        if(q[i].cnt%k)
        {
            printf("%lld",q[i].num);
            break;
        }
    }
}