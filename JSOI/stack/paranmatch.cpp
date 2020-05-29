#include<bits/stdc++.h>
using namespace std;
stack<int>s;
string str;
char ans[101];
int i;
int main()
{
    cin>>str;
    for(;str[i];i++)
    {
        ans[i]=' ';
        switch(str[i])
        {
            case '(':
            {
                s.push(i);
                break;
            }
            case ')':
            {
                if(s.size())s.pop();
                else ans[i]='?';
                break;
            }
        }
    }
    ans[i]=0;
    while(s.size())
    {
        ans[s.top()]='$';
        s.pop();
    }
    cout<<str<<endl<<ans;
    return 0;
}