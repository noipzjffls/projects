#include<bits/stdc++.h>
using namespace std;
int n;
string s[51];
bool check(string a,int id)
{
    for(int i=1;i<=n;i++)
    {
        if(i==id)continue;
        if(s[i].substr(0,a.size())==a)return false;
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s[i].size();j++)
        {
            string sub=s[i].substr(0,j);
            if(check(sub,i))
            {
                cout<<sub<<endl;
                break;
            }
        }
    }
    return 0;
}