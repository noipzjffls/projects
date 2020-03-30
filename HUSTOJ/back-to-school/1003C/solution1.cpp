#include<cstdio>
#include<map>
char c[100001],s;
int i,x,y;
std::map<char,int>m;
int main()
{
    gets(c);
    for(;c[i];i++)m[c[i]]++;
    for(s=-128;s<127;s++)if(m[s]>x){x=m[s];y=s;}
    printf("%c",y);
}