#include<bits/stdc++.h>
using namespace std;
int n,ans,t[21];
char ch;
string s[21];
string transfer(string a,string b)
{
    for(int i=0,j=a.size()-1;a[i]&&b[i];i++,j--)
    {
        string na=a.substr(j),nb=b.substr(0,i+1);
        if(na==nb&&na!=a&&nb!=b)return a+b.substr(i+1);
    }
    return "ERROR";
}
void dfs(string cur)
{
    for(int i=1;i<=n;i++)
    {
        if(t[i]>1)continue;
        string ns=transfer(cur,s[i]);
        if(ns=="ERROR")continue;
        t[i]++;
        dfs(ns);
        t[i]--;
    }
    ans=max(ans,int(cur.size()));
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    cin>>ch;
    for(int i=1;i<=n;i++)
    {
        if(s[i][0]==ch)
        {
            memset(t,0,sizeof(t));
            t[i]++;
            dfs(s[i]);
        }
    }
    cout<<ans;
    return 0;
}