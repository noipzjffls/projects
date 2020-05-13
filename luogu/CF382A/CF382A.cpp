#include<bits/stdc++.h>
using namespace std;
string s,t,sa,sb;
int line;
bool flag;
int main()
{
    cin>>s>>t;
    line=s.find('|');
    sa=s.substr(0,line);
    sb=s.substr(line+1);
    if(sa.size()<sb.size())
    {
        swap(sa,sb);
        flag=true;
    }
    if(sb.size()+t.size()<sa.size())
    {
        puts("Impossible");
        return 0;
    }
    while(!t.empty()&&sa.size()!=sb.size())
    {
        sb+=t[0];
        t.erase(0,1);
    }
    if(t.size()&1)
    {
        puts("Impossible");
        return 0;
    }
    for(int i=0;t[i];i++)
    {
        if(i&1)sa+=t[i];
        else sb+=t[i];
    }
    if(flag)swap(sa,sb);
    cout<<sa<<'|'<<sb;
    return 0;
}