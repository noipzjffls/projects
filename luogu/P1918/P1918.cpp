#include<bits/stdc++.h>
using namespace std;
map<int,int>M;
int n,m,q;
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
    for(int i=1;i<=n;i++)M[read()]=i;
    q=read();
    while(q--)printf("%d\n",M[read()]);
    return 0;
}