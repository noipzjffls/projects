#include<bits/stdc++.h>
using namespace std;
int n;
char last;
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
    int lena=a.size(),lenb=b.size(),lenc=1,A[10000]={0},B[10000]={0},C[10000]={0},i;
    bool flag=false;
    if(lena<lenb||lena==lenb&&a<b)
    {
        flag=true;
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
    if(flag)result='-'+result;
    return result;
}
string Multiply(string a,string b)
{
    int lena=a.size(),lenb=b.size(),lenc=1,A[10000]={0},B[10000]={0},C[20000]={0},i,j,x=0;
    string result="";
    for(i=0;i<lena;i++)A[lena-i]=a[i]-'0';
    for(i=0;i<lenb;i++)B[lenb-i]=b[i]-'0';
    for(i=1;i<=lena;i++)
    {
        x=0;
        for(j=1;j<=lenb;j++)
        {
            C[i+j-1]+=A[i]*B[j]+x;
            x=C[i+j-1]/10;
            C[i+j-1]%=10;
        }
        C[lenb+i]=x;
    }
    lenc=lena+lenb;
    while(!C[lenc]&&lenc>1)lenc--;
    for(i=lenc;i;i--)result+=C[i]+'0';
    return result;
}
string work(string a,string b,char opt)
{
    switch(opt)
    {
        case '+':return Add(a,b);
        case '-':return Minus(a,b);
        case '*':return Multiply(a,b);
    }
    return "ERROR";
}
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
int main()
{
    cin>>n;
    while(n--)
    {
        string a,b,c,ans;
        cin>>a;
        if(a.size()==1&&isalpha(a[0]))
        {
            cin>>b>>c;
            a[0]=transfer(a[0]);
            ans=b+a+c+'='+work(b,c,a[0]);
            last=a[0];
        }
        else
        {
            cin>>b;
            ans=a+last+b+'='+work(a,b,last);
        }
        cout<<ans<<endl<<ans.size()<<endl;
    }
    return 0;
}