#include<bits/stdc++.h>
using namespace std;
double x,y,r;
int main()
{
    cin>>x>>y>>r;
    printf("%f\n",fabs(sqrt(x*x+y*y)-2*r));
    if(!x&&!y)puts("0.00");
    else if(!y)puts("Error");
    else printf("%.2f\n",fabs(x/y));
    return 0;
}