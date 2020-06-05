#include<bits/stdc++.h>
using namespace std;
long long l,r,mid;
int cnt;
string result;
int main()
{
    scanf("%lld%lld",&l,&r);
    if(l>r)swap(l,r);
    while(l<=r)
    {
        mid=(l+r)>>1;
        printf("%lld\n",mid);
        cnt++;
        while(cin>>result)
        {
            if(result=="YES")
            {
                printf("%d\n",cnt);
                return 0;
            }
            if(result=="HIGH")
            {
                r=mid-1;
                break;
            }
            else if(result=="LOW")
            {
                l=mid+1;
                break;
            }
            else puts("Error!");
        }
    }
    return 0;
}