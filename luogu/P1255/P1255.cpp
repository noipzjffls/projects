#include<bits/stdc++.h>
using namespace std;
string a,b;
int n;
string add(string a,string b)
{
    int lena=a.size(),lenb=b.size(),lenc=1,A[10000]={0},B[10000]={0},C[20000]={0},i,x=0;
    string result="";
    for(i=0;i<lena;i++)A[lena-i]=a[i]-'0';
    for(i=0;i<lenb;i++)B[lenb-i]=b[i]-'0';
    while(lenc<=lena||lenc<=lenb)
    {
        C[lenc]=A[lenc]+B[lenc]+x;
        x=C[lenc]/10;
        C[lenc]%=10;
        lenc++;
    }
    C[lenc]=x;
    if(!C[lenc])lenc--;
    for(i=lenc;i;i--)result+=C[i]+'0';
    return result;
}
int main()
{
	scanf("%d",&n);
	if(n<4)
	{
		printf("%d",n);
		return 0;
	}
	a="2";
	b="3";
	for(int i=4;i<n;i++)
	{
		string t=a; 
		a=b;
		b=add(t,b);
	}
	cout<<add(a,b);
	return 0;
}
