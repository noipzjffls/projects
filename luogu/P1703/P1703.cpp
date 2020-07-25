#include<bits/stdc++.h>
using namespace std;
string key,ans;
int m;
int main()
{
    cin>>key>>ans;
    for(int i=0;key[i];i++)key[i]=tolower(key[i]);
    for(int i=0,j=0,x;ans[i];i++,j=(j+1)%key.size())
    {
        x=ans[i]+key[j]-'a';
        if((islower(ans[i])&&x>'z')||(isupper(ans[i])&&x>'Z'))x-=26;
        ans[i]=x;
    }
    scanf("%d",&m);
    for(int i=0,a,b;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        a--;
        b--;
        string s=ans.substr(a,b-a+1);
        reverse(s.begin(),s.end());
        ans.replace(a,b-a+1,s);
    }
    cout<<ans;
}