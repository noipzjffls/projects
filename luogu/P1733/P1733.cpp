#include<bits/stdc++.h>
using namespace std;
int l=1,r=1e9,mid,result;
int main()
{
    while(l<=r)
    {
        mid=l+r>>1;
        cout<<mid<<endl;
        cin>>result;
        switch(result)
        {
            case 1:
            {
                r=mid-1;
                break;
            }
            case -1:
            {
                l=mid+1;
                break;
            }
            default:return 0;
        }
    }
    return 0;
}