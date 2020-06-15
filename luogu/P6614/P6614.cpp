#include<bits/stdc++.h>
using namespace std;
int n,a,b,pos;
struct point
{
    int x,y;
}p[100001];
bool cmp(point A,point B)
{
    if(A.x!=B.x)return A.x<B.x;
    return A.y>B.y;
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y);
    sort(p+1,p+n+1,cmp);
    pos=n/(a+b)*a;
    printf("1000000000000 %d %d",p[pos].x,p[pos].y);
    return 0;
}