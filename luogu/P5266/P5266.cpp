#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>m;
int n,cnt;
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
    while(n--)
    {
        string name;
        switch(read())
        {
            case 1:
            {
                cin>>name;
                if(!m[name])cnt++;
                m[name]=read();
                puts("OK");
                break;
            }
            case 2:
            {
                cin>>name;
                if(m[name])printf("%d\n",m[name]);
                else puts("Not found");
                break;
            }
            case 3:
            {
                cin>>name;
                if(m[name])
                {
                    m[name]=0;
                    cnt--;
                    puts("Deleted successfully");
                }
                else puts("Not found");
                break;
            }
            default: printf("%d\n",cnt);
        }
    }
}