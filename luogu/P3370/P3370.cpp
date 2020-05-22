#include<bits/stdc++.h>
using namespace std;
priority_queue<string>q;
int n,ans;
string t;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        q.push(s);
    }
    t=q.top();
    while(!q.empty())
    {
        do q.pop();
        while(q.top()==t&&!q.empty());
        ans++;
        t=q.top();
    }
    cout<<ans;
    return 0;
}