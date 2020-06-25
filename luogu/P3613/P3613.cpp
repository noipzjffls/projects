#include<bits/stdc++.h>
using namespace std;
int n,q,M=1e5;
unordered_map<int,int>m;
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
    q=read();
    for(int t=0,i,j,k;t<q;t++)
    {
        if(read()==1)
        {
            i=read();
            j=read();
            k=read();
            m[i*M+j]=k;
        }
        else printf("%d\n",m[read()*M+read()]);
    }
    return 0;
}