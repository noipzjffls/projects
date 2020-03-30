#include<bits/stdc++.h>
#define check(d)(bool)(d<1&&d>0?1:0)
long long a,b,c;
double delta,x,y;
int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    if(!a)
    {
        x=-1.0*c/b;
        if(check(x))printf("%.6f",x);
        else printf("Error");
    }
    else
    {
        delta=b*b-4*a*c;
        if(delta<0)
        {
            printf("Error");
            return 0;
        }
        if(!delta)
        {
            x=-1.0*b/2/a;
            if(check(x))printf("%.6f",x);
            else printf("Error");
            return 0;
        }
        x=(-b-sqrt(delta))/2/a;
        y=(sqrt(delta)-b)/2/a;
        if(x>y)std::swap(x,y);
        if(check(x))printf("%.6f ",x);
        if(check(y))printf("%.6f",y);
        if(!check(x)&&!check(y))printf("Error");
    }
}