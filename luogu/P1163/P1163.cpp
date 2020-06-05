#include<bits/stdc++.h>
using namespace std;
double a,b,c,l,r=5;
int main()
{
    cin>>a>>b>>c;
    while(l<=r)
    {
        double mid=(l+r)/2;
        if(pow(1.0/(1+mid),c)>1-a*mid/b)r=mid;
        else l=mid;
        if(fabs(l-r)<1e-7)break;
    }
    printf("%.1f",l*100);
    return 0;
}