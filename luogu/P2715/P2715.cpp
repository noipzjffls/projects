#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
int a,b,x,y,z;
double ans;
int pos()
{
    int a[4]={s.find('+'),s.find('-'),s.find('*'),s.find('/')};
    for(int i=0;i<4;i++)
    {
        if(a[i]==string::npos)continue;
        return a[i];
    }
    return -1;
}
int f(string s)
{
    int x=0;
    for(int i=0;s[i];i++)
    {
        if(!isdigit(s[i]))break;
        x=(x<<3)+(x<<1)+(s[i]^48);
    }
    return x;
}
int main()
{
    getline(cin,s);
    for(int i=0;s[i];)
    {
        if(s[i]==' ')s.erase(i,1);
        else i++;
    }
    a=pos();
    b=s.find('=');
    s1=s.substr(0,a);
    s2=s.substr(a+1,b-a-1);
    s3=s.substr(b+1);
    x=f(s1);
    y=f(s2);
    z=f(s3);
    switch(s[a])
    {
        case '+':
        {
            if(s1=="?")ans=z-y;
            else if(s2=="?")ans=z-x;
            else ans=x+y;
            break;
        }
        case '-':
        {
            if(s1=="?")ans=y+z;
            else if(s2=="?")ans=x-z;
            else ans=x-y;
            break;
        }
        case '*':
        {
            if(s1=="?")ans=1.0*z/y;
            else if(s2=="?")ans=1.0*z/x;
            else ans=x*y;
            break;
        }
        case '/':
        {
            if(s1=="?")ans=y*z;
            else if(s2=="?")ans=1.0*x/z;
            else ans=1.0*x/y;
            break;
        }
    }
    printf("%.2lf",ans);
    return 0;
}