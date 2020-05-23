#include<bits/stdc++.h>
using namespace std;
int l,dp[1000001],ans=-1,tot;
char a[1000001];
int main()
{
    scanf("%s",a);
    l=strlen(a);
    for(int i=l-1;i>=0;i--)
    {
        if(a[i]==')'||a[i]==']')continue;
        if((a[i+1+dp[i+1]]==')'&&a[i]=='(')||(a[i+1+dp[i+1]]==']'&&a[i]=='['))
        {
            dp[i]=dp[i+1]+2;
            dp[i]+=dp[i+dp[i]];
            if(ans<=dp[i])
            {
                ans=dp[i];
                tot=i;
            }
        }
    }
    for(int i=tot;i<ans+tot;i++)cout<<a[i];
    return 0;
}