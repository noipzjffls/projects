#include<bits/stdc++.h>
using namespace std;
int n,m,t[1001];
int main()
{
    cin>>n>>m;
    while(m--)
    {
        stack<int>s;
        int a=1,b=1;
        for(int i=1;i<=n;i++)scanf("%d",&t[i]);
        string text="Yes\n";
        while(b<=n)
        {
            if(a==t[b])a++,b++;
            else if(s.size()&&s.top()==t[b])s.pop(),b++;
            else if(a<=n)s.push(a++);
            else
            {
                text="No\n";
                break;
            }
        }
        cout<<text;
    }
    return 0;
}