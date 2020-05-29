#include<bits/stdc++.h>
using namespace std;
int n,num,ans;
stack<int>s;
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
    for(int i=0;i<n<<1;i++)
    {
        string command;
        cin>>command;
        if(command=="add")s.push(read());
        else
        {
            num++;
            if(s.size())
            {
                if(s.top()==num)s.pop();
                else
                {
                    ans++;
                    while(s.size())s.pop();
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}