#include<cstdio>
#pragma GCC optimize(2)
using namespace std;
int n,a,b,i,j,k,s;
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
void write(int x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)write((x>>1)/5);
    putchar(x%10+'0');
}
int main()
{
    n=read();
    a=(read()>>1)+read();
    b=read();
    if(a+(b<<1)<n)
    {
        putchar('0');
        return 0;
    }
    for(i=0;i<=n&&i<=a;i++)if(!((n-i)&1)&&((n-i)>>1)<=b)s++;
    write(s);
}