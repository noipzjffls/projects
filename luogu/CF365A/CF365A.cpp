#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
string s;
bool check(string x)
{
    bool flag[10]={false};
    for(int i=0;x[i];i++)
    {
        if(x[i]>k+48)break;
        flag[x[i]^48]=true;
    }
    for(int i=0;i<=k;i++)if(!flag[i])return false;
    return true;
}
int main()
{
    cin>>n>>k;
    while(n--)
    {
        cin>>s;
        sort(s.begin(),s.end());
        ans+=check(s);
    }
    cout<<ans;
    return 0;
}