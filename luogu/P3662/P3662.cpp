#include<bits/stdc++.h>
using namespace std;
int n,k,b,s[100005],ans=1<<30;
bool flag[100005];
int main()
{
    cin>>n>>k>>b;
    while(b--)
    {
        int u;
        scanf("%d",&u);
        flag[u]=true;
    }
    for(int i=1;i<=n;i++)s[i]=s[i-1]+flag[i];
    for(int i=k;i<=n;i++)ans=min(ans,s[i]-s[i-k]);
    cout<<ans;
    return 0;
}