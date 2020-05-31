#include<bits/stdc++.h>
using namespace std;
string o;
string Add(string a,string b)
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
string Minus(string a,string b)
{
    int lena=a.size(),lenb=b.size(),lenc=1,A[200]={0},B[200]={0},C[200]={0},i;
    if(lena<lenb||lena==lenb&&a<b)
    {
        swap(lena,lenb);
        swap(a,b);
    }
    string result="";
    for(i=0;i<lena;i++)A[lena-i]=a[i]-'0';
    for(i=0;i<lenb;i++)B[lenb-i]=b[i]-'0';
    while(lenc<=lena)
    {
        if(A[lenc]<B[lenc])
        {
            A[lenc]+=10;
            A[lenc+1]--;
        }
        C[lenc]=A[lenc]-B[lenc];
        lenc++;
    }
    while(!C[lenc]&&lenc>1)lenc--;
    for(i=lenc;i;i--)result+=C[i]+'0';
    return result;
}
int main()
{
    cin>>o;
    if(o=="0"||o[0]=='-')
    {
        putchar('0');
        return 0;
    }
    cout<<Minus(Add(o,o),"1");
    return 0;
}