#include<bits/stdc++.h>
#define l long double
using namespace std;
l k,b,dis;
struct point
{
    l x,y;
}A,B,C,M[5],N[5];
int main()
{
    cin>>k>>b;
    A.x=-b/k;
    B.y=b;
    dis=sqrt(pow(A.x,2)+pow(B.y,2));
    M[1].y=-B.y;
    if(b>0)M[1].y=B.y;
    N[1].x=-A.x;
    M[2].y=B.y+dis;
    M[3].y=B.y-dis;
    N[2].x=N[3].x=A.x;
    N[2].y=dis;
    N[3].y=-dis;
    C.x=abs(A.x);
    C.y=abs(B.y);
    dis=(pow(C.y,2)-pow(C.x,2))/2/C.y;
    if(b<0)M[4].y=-dis;
    else M[4].y=dis;
    N[4].x=A.x;
    if(B.y>M[4].y)N[4].y=A.y+abs(abs(B.y)-abs(M[4].y));
    else N[4].y=A.y-abs(abs(B.y)-abs(M[4].y));
    for(int i=1;i<5;i++)printf("%.6Lf %.6Lf\n",M[i].x,M[i].y);
    for(int i=1;i<5;i++)printf("%.6Lf %.6Lf\n",N[i].x,N[i].y);
}