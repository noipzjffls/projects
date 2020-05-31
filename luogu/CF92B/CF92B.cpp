#include<bits/stdc++.h>
using namespace std;
string s;
int pos,ans;
int main()
{
    cin>>s;
    pos=s.size()-1;
    while(pos)
    {
        ans++;
        switch(s[pos])
        {
            case '1':
            {
                s[pos]='0';
                s[pos-1]++;
                break;
            }
            case '2':
            {
                s[--pos]++;
                break;
            }
            default:pos--;
        }
    }
    if(s[0]=='2')ans++;
    printf("%d",ans);
    return 0;
}