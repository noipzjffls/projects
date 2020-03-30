#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,a[10001],t=-9187201950435737472,k,b;
char c;
bool check(long long s)
{
    bool f1=0,f2=0;
    while(s)
    {
        if(s%10-4&&s%10-1)return 0;
        f1+=s%10==4;
        f2+=s%10==1;
        s/=10;
    }
    return f1*f2;
}
void print(long long s)
{
    if(check(s))cout<<"April Fools!\n";
    else cout<<s<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    memset(a,0x80,sizeof(a));
    cin>>n>>m>>x>>y;
    k=(y-1)/(x-1);
    b=1-k;
    while(m--)
    {
        cin>>c;
        if(c=='Q')
        {
            int l;
            cin>>l;
            if(a[l]-t)print(a[l]);
            else print(l*k+b);
        }
        else
        {
            int l,L;
            cin>>l>>L;
            a[l]=L;
        }
    }
}