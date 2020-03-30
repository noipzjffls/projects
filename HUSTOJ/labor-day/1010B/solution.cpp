#include<bits/stdc++.h>
#define l long double
#define m 3.1415926535/180
#define M 180/3.1415926535
using namespace std;
l t1,t2,t3,t4,dir,fa,fb;
int main()
{
    while(cin>>fa>>fb>>dir)
    {
        if(fabs(dir)<1e-9)
        {
            printf("%.6Lf 0\n",fa+fb);
            continue;
        }
        else if(dir==180)
        {
            if(fa==fb)
            {
                printf("0\n");
                continue;
            }
            if(fa>fb)printf("%.6Lf 0\n",fa-fb);
            else printf("%.6Lf 180\n",fb-fa);
            continue;
        }
        t1=cos(dir*m)*fa;
        t2=sin(dir*m)*fa;
        t3=sqrt(pow(fb+t1,2)+pow(t2,2));
        t4=asin(t2/t3)*M;
        if(t3<0)
        {
            t3=-t3;
            t4+=180;
            if(t4>360)t4-=360;
        }
        printf("%.6Lf ",t3);
        if(fabs(t3)>1e-9)printf("%.6Lf\n",t4);
        else printf("\n");
    }
}