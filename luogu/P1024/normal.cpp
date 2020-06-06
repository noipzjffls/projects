#include<bits/stdc++.h>
using namespace std;
double a,b,c,d,ans,x;
int main()
{
    cin>>a>>b>>c>>d;
    for(x=-100;x<=100;x+=0.01)
    {
        ans=a*x*x*x+b*x*x+c*x+d;
        if(fabs(ans)<1e-7)printf("%.2lf ",x);
    }
    return 0;
}