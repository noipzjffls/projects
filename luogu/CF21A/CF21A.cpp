//Record: 32519542, Result: WA@7, Type: RMJ - CF
#include<iostream>
using namespace std;
int pos;
string address,resource,username,hostname;
void Exit(bool flag)
{
    if(flag)printf("YES");
    else printf("NO");
    exit(0);
}
bool check(string s)
{
    if(s.empty()||s.size()>16)return 0;
    for(int i=0;i<s.size();i++)if(!isalpha(s[i])&&!isdigit(s[i])&&s[i]!='_')return 0;
    return 1;
}
int main()
{
    getline(cin,address);
    pos=address.find('/');
    if(pos!=string::npos)
    {
        resource=address.substr(pos+1);
        if(!check(resource))Exit(0);
        address.erase(pos);
    }
    pos=address.find('@');
    username=address.substr(0,pos);
    if(!check(username))Exit(0);
    address.erase(0,pos+1);
    if(address.empty()||address.size()>32)Exit(0);
    pos=address.find('.');
    while(pos!=string::npos)
    {
        hostname=address.substr(0,pos);
        if(hostname.empty()||hostname.size()>16)Exit(0);
        address.erase(0,pos+1);
        pos=address.find('.');
    }
    if(!check(address))Exit(0);
    Exit(1);
}