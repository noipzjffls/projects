#include<bits/stdc++.h>
using namespace std;
int n;
string f[20001]={"0","2(0)","2"};
string ans(int x)
{
    if(f[x]!="")return f[x];
    int p=log2(x),q=1<<p;
    if(q==x)return f[x]="2("+ans(p)+")";
    return f[x]=ans(q)+'+'+ans(x-q);
}
int main()
{
	scanf("%d",&n);
	cout<<ans(n);
    return 0;
}
