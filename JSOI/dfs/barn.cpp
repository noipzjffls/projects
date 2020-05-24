#include<bits/stdc++.h>
using namespace std;
int L,C,a[30];
string s;
bool consonant(char ch)
{
    switch(ch)case 'a':case 'e':case 'i':case 'o':case 'u':return false;
    return true;
}
void dfs(int k)
{
    if(k>L)
    {
        string t="";
        int sum=0;
        for(int i=1;i<=L;i++)
        {
            sum+=consonant(s[a[i]-1]);
            t+=s[a[i]-1];
        }
        if(t.size()-sum>0&&sum>1)cout<<t<<endl;
        return;
    }
    for(int i=a[k-1]+1;i<=C;i++)
    {
        a[k]=i;
        dfs(k+1);
    }
}
int main()
{
    cin>>L>>C;
    for(int i=1;i<=C;i++)
    {
        char ch;
        cin>>ch;
        s+=ch;
    }
    sort(s.begin(),s.end());
    dfs(1);
    return 0;
}