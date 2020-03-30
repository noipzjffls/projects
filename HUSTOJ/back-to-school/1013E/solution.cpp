#include<bits/stdc++.h>
using namespace std;
int n,x,y,z,a[2000001]={1,1},t;
string s,ans;
int check(char c)
{
    if(c=='8')return 1;
    string S="cfhijklmnrstuvwxyz12357";
    for(int i=0;i<S.size();i++)
    {
        if(c==S[i])
        {
            printf("-1");
            exit(0);
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>s;
    for(int j=0;j<s.size();j++)x+=check(s[j]);
    x*=n;
    for(int i=0;i<x;i++)
    {
        t=0;
        for(int j=1;j<=a[0];j++)
        {
            a[j]*=2;
            a[j]+=t;
            t=a[j]/10;
            a[j]%=10;
        }
        if(x)
        {
            a[0]++;
            a[a[0]]=t;
        }
    }
    for(int i=a[0];i;i--)
    {
        if(a[i])
        {
            z=i;
            break;
        }
    }
    for(int i=z;i;i--)printf("%d",a[i]);
}