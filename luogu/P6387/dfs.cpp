#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
string s;
int a[10],b[10],len,n,minn=1e7;
bool flag[10];
void dfs(int k)
{
    if(k>len)
    {
        int num=0;
        for(int i=1;i<=len;i++)num=(num<<3)+(num<<1)+a[b[i]];
        if(num>n&&num<minn)minn=num;
        return;
    }
    for(int i=1;i<=len;i++)
    {
        if(!flag[i])
        {
            flag[i]=1;
            b[k]=i;
            dfs(k+1);
            flag[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>s;
    len=s.size();
    for(int i=0,j=len-i-1;i<len;i++)
    {
        a[i+1]=s[i]^'0';
        n=(n<<3)+(n<<1)+a[i+1];
    }
    dfs(1);
    printf("%d",minn==1e7?0:minn);
}