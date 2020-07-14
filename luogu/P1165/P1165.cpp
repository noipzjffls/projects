#include<bits/stdc++.h>
using namespace std;
int n,f[200001],p;
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
    scanf("%d",&n);
    while(n--)
    {
        switch(read())
        {
            case 0:
            {
                int x=read();
                p++;
                f[p]=max(f[p-1],x);
                break;
            }
            case 1:
            {
                if(p)p--;
                break;
            }
            case 2:
            {
                printf("%d\n",f[p]);
                break;
            }
            default:puts("Luogu is the best!");
        }
    }
    return 0;
}