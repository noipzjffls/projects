#include<bits/stdc++.h>
using namespace std;
int a,m=1e4,opd;
char opt;
stack<int>s;
int main()
{
    cin>>a;
    a%=m;
    s.push(a);
    while(cin>>opt>>opd)
    {
        if(opt=='*')
        {
            a=s.top();
            s.pop();
            s.push(a*opd%m);
        }
        else s.push(opd);
    }
    a=0;
    while(!s.empty())
    {
        a+=s.top();
        a%=m;
        s.pop();
    }
    cout<<a;
    return 0;
}