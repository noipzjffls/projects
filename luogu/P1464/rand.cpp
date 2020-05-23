#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("input.txt","w",stdout);
    srand(time(NULL));
    n=rand()%20+1;
    while(n--)
    {
        long long x=rand(),y=rand(),z=rand(),t1=rand()%2,t2=rand()%2,t3=rand()%2;
        if(t1)x=-x;
        if(t2)y=-y;
        if(t3)z=-z;
        printf("%lld %lld %lld\n",x,y,z);
    }
    puts("-1 -1 -1");
    return 0;
}