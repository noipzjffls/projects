#include<bits/stdc++.h>
using namespace std;
int n;
stack<int>dish,washed,dried;
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
    for(int i=n;i;i--)dish.push(i);
    while(dried.size()!=n)
    {
        int x,y;
        x=read();
        y=read();
        if(x==1)
        {
            while(y--)
            {
                washed.push(dish.top());
                dish.pop();
            }
        }
        else
        {
            while(y--)
            {
                dried.push(washed.top());
                washed.pop();
            }
        }
    }
    while(!dried.empty())
    {
        printf("%d\n",dried.top());
        dried.pop();
    }
}