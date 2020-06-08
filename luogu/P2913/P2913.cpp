#include<bits/stdc++.h>
using namespace std;
int n,t;
bool b;
int main()
{
    scanf("%d",&n);
    while(--n)
    {
        scanf("%d%d%d",&t,&t,&t);
        b^=t;
    }
    printf("%d",b);
    return 0;
}