#include<bits/stdc++.h>
using namespace std;
int n;
string ans="0",text,num;
string add(string a,string b)
{
    int lena=a.size(),lenb=b.size(),lenc=1,A[200]={0},B[200]={0},C[200]={0},i,x=0;
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
bool check(string x,string y)
{
    if(x.size()-y.size())return x.size()>y.size();
    for(int i=0;i<x.size();i++)if(x[i]-y[i])return x[i]>y[i];
    return 1;
}
int main()
{
    cin>>n;
    while(n--)
    {
        cin>>text>>num;
        if(text=="task")
        {
            if(num[0]!='-')num='-'+num;
            else num.erase(0,1);
        }
        if(ans[0]!='-')
        {
            if(num[0]!='-')ans=add(ans,num);
            else
            {
                num.erase(0,1);
                if(check(ans,num))ans=Minus(ans,num);
                else ans='-'+Minus(ans,num);
            }
        }
        else
        {
            if(num[0]=='-')
            {
                ans.erase(0,1);
                num.erase(0,1);
                ans='-'+add(num,ans);
            }
            else
            {
                ans.erase(0,1);
                if(check(num,ans))ans=Minus(num,ans);
                else ans='-'+Minus(num,ans);
            }
        }
    }
    cout<<ans;
}