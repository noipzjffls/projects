#include<bits/stdc++.h>
using namespace std;
long long read()
{
    long long x=0,f=1;
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
long long ans[21][21][21],x,y,z;
long long w(long long a,long long b,long long c)
{
    if(a<=0||b<=0||c<=0)return 1;
    if(a>20||b>20||c>20)return w(20,20,20);
    if(ans[a][b][c]>0)return ans[a][b][c];
    if(a<b&&b<c)return ans[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    return ans[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
int main()
{
    while(true)
    {
        x=read();
        y=read();
        z=read();
        if(x==-1&&y==-1&&z==-1)break;
        printf("w(%lld, %lld, %lld) = %lld\n",x,y,z,w(x,y,z));
    }
    return 0;
}