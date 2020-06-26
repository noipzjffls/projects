#include<bits/stdc++.h>
using namespace std;
string n,ans;
int k;
bool cmp(string a,string b)
{
    if(a.size()!=b.size())return a.size()>b.size();
    for(int i=0;a[i];i++)if(a[i]!=b[i])return a[i]>b[i];
    return false;
}
string mins(string a,string b)
{
    return cmp(a,b)?b:a;
}
void f(string &s)
{
    if(s.size()==1)return;
    while(s[0]=='0')s.erase(0,1);
}
void dfs(string cur,int cnt)
{
    if(cnt==k)
    {
        ans=mins(ans,cur);
        return;
    }
    string ns=cur;
    for(int i=0;cur[i];i++)
    {
        string t=cur;
        t.erase(i,1);
        f(t);
        ns=mins(ns,t);
    }
    dfs(ns,cnt+1);
}
int main()
{
    cin>>n>>k;
    ans.insert(0,255,'9');
    dfs(n,0);
    cout<<ans;
    return 0;
}