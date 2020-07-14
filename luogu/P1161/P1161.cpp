#include<bits/stdc++.h>
using namespace std;
map<int,bool>lights;
int n;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        double a,t;
        scanf("%lf%lf",&a,&t);
        for(int i=1;i<=t;i++)lights[int(a*i)]^=1;
    }
    for(int i=1;;i++)
    {
        if(lights[i])
        {
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}