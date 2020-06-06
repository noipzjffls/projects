#include<bits/stdc++.h>
using namespace std;
double a,b,c,d,A,B,C,T,theta,x[4];
int main()
{
    cin>>a>>b>>c>>d;
    A=b*b-3*a*c;
    B=b*c-9*a*d;
    C=c*c-3*b*d;
    T=(2*A*b-3*a*B)/(2*sqrt(A*A*A));
    theta=acos(T);
    x[1]=((-b-2*sqrt(A)*cos(theta/3)))/3/a;
    x[2]=(-b+sqrt(A)*(cos(theta/3)+sqrt(3)*sin(theta/3)))/3/a;
    x[3]=(-b+sqrt(A)*(cos(theta/3)-sqrt(3)*sin(theta/3)))/3/a;
    sort(x+1,x+4);
    printf("%.2lf %.2lf %.2lf",x[1],x[2],x[3]);
    return 0;
}