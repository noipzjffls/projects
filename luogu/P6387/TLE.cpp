#include<bits/stdc++.h>
using namespace std;
int x;
string origin,newstr;
string transfer(int n)
{
    stringstream ss;
    string s;
    ss<<n;
    ss>>s;
    return s;
}
int main()
{
    scanf("%d",&x);
    origin=transfer(x);
    sort(origin.begin(),origin.end());
    for(int i=x+1;i<pow(transfer(x).size(),10);i++)
    {
        newstr=transfer(i);
        sort(newstr.begin(),newstr.end());
        if(newstr==origin)
        {
            printf("%d",i);
            return 0;
        }
    }
    putchar('0');
}