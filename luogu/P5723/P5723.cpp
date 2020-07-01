#include<bits/stdc++.h>
using namespace std;
int l,cnt=1;
bool p(int x)
{
    if(x<2)return false;
    for(int i=2;i*i<=x;i++)if(x%i==0)return false;
    return true;
}
int main()
{
    scanf("%d",&l);
    if(l<2)
    {
        putchar('0');
        return 0;
    }
    puts("2");
    l-=2;
    for(int i=3;;i+=2)
    {
        if(p(i))
        {
            l-=i;
            if(l<0)
            {
                printf("%d\n",cnt);
                return 0;
            }
            printf("%d\n",i);
            cnt++;
        }
    }
    return 0;
}