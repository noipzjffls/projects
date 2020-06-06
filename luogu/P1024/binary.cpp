#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
double ans(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
void search(double l,double r)
{
    if(r-l<=1e-3)
    {
        printf("%.2lf ",l);
        return;
    }
    double mid=l+(r-l)*0.5,ans1=ans(l)*ans(mid),ans2=ans(mid)*ans(r);
    if(!ans(mid))printf("%.2lf ",mid);
    if(!ans(r))printf("%.2lf ",r);
    if(ans1<0)search(l,mid);
    else if(ans2<0)search(mid,r);
}
int main()
{
    cin>>a>>b>>c>>d;
    for(int i=-100;i<100;i++)
    {
        if(ans(i)*ans(i+1)>0)continue;
        search(i,i+1);
    }
    return 0;
}