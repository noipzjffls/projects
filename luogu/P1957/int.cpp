#include<bits/stdc++.h>
using namespace std;
int n;
char last;
char transfer(char ch)
{
    switch(ch)
    {
        case 'a':return '+';
        case 'b':return '-';
        case 'c':return '*';
    }
    return '?';
}
int work(int a,int b,char opt)
{
    switch(opt)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
    }
    return 1<<30;
}
int main()
{
    cin>>n;
    while(n--)
    {
        string a;
        int b,c;
        cin>>a;
        if(a.size()==1&&isalpha(a[0]))
        {
            last=transfer(a[0]);
            cin>>b>>c;
        }
        else
        {
            b=stoi(a);
            cin>>c;
        }
        string ans=to_string(b)+last+to_string(c)+'='+to_string(work(b,c,last));
        cout<<ans<<endl<<ans.size()<<endl;
    }
    return 0;
}