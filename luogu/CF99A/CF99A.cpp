#include<bits/stdc++.h>
using namespace std;
string s;
int point;
int main()
{
    cin>>s;
    point=s.find('.');
    if(point==-1)
    {
        if(s[s.size()-1]=='9')puts("GOTO Vasilisa.");
        else cout<<s;
        return 0;
    }
    if(s[point-1]=='9')puts("GOTO Vasilisa.");
    else if(s[point+1]>'4')
    {
        s=s.substr(0,point);
        int pos=s.size()-1;
        s[pos]++;
        while(s[pos]==58&&!pos)
        {
            s[pos]=48;
            s[pos--]++;
        }
        if(s[0]==58)
        {
            s='1'+s;
            s[1]=48;
        }
        cout<<s;
    }
    else cout<<s.substr(0,point);
    return 0;
}