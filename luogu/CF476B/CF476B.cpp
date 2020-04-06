#include<bits/stdc++.h>
#define ll long long
using std::queue;
queue<bool>s;
char ch;
ll x,y,z,cnt,ans,n;
bool l;
void f(ll n)
{
    if(n>0)
    {
        f(n/2);
        s.push(n%2);
    }
}
int main()
{
    do
    {
        ch=getchar();
        if(ch!='\n')x+=ch=='+'?1:-1;
    }while(ch!='\n');
    do
    {
        ch=getchar();
        if(ch!='\n')y+=ch=='+'?1:ch=='-'?-1:0;
        cnt+=ch=='?';
    }while(ch!='\n');
    if(!cnt)
    {
        printf("%d",x==y);
        return 0;
    }
    n=1<<cnt;
    for(ll i=0;i<n;i++)
    {
        z=y;
        f(i);
        while(!s.empty())
        {
            if(s.front())z++;
            else z--;
            s.pop();
        }
        if(z==x)ans++;
    }
    printf("%.10f",1.0*ans/n);
}