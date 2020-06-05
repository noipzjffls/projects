#include<bits/stdc++.h>
using namespace std;
int n;
string str;
void print(int x)
{
    if(x>26)
    {
        if(x%26)
        {
            print(x/26);
            putchar(x%26+'A'-1);
        }
        else
        {
            print(x/26-1);
            putchar('Z');
        }
    }
    else putchar(x+'A'-1);
}
bool type(string s)
{
    int k=1,f=0;
    while(k<s.size())
    {
        if(isdigit(s[k])&&!isdigit(str[k-1]))f++;
        k++;
    }
    return f==2;
}
int num(string s)
{
    int x=0;
    for(int i=0;s[i];i++)x=(x<<3)+(x<<1)+(s[i]^48);
    return x;
}
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        cin>>str;
        int x=str.find('R'),y=str.find('C');
        if(type(str))
        {
            int a=num(str.substr(x+1,y-x-1)),b=num(str.substr(y+1));
            print(b);
            printf("%d\n",a);
        }
        else
        {
            int p,a,b=0;
            for(p=0;;p++)if(isdigit(str[p]))break;
            a=num(str.substr(p));
            for(int i=0;i<p;i++)b=b*26+str[i]-'A'+1;
            printf("R%dC%d\n",a,b);
        }
    }
    return 0;
}