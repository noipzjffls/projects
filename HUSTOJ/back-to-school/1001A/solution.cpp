#include<bits/stdc++.h>
using namespace std;
long double a,b,s;
int d,p,i;
string x;
int main()
{
    ios::sync_with_stdio(0);
    scanf("%Lf%Lf%d",&a,&b,&d);
    s=a/b;
    x=to_string(s);
    for(;x[p]!='.';p++)printf("%c",x[p]);
    p++;
    if(d)printf(".");
    for(i=0;i<d;i++,p++)printf("%c",x[p]);
}