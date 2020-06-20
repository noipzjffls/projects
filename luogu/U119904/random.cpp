#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    srand(time(NULL));
    t=rand()%20+1;
    cout<<t<<endl;
    for(int i=0,n;i<t;i++)
    {
        n=rand()%19+2;
        cout<<n<<endl;
        for(int j=0;j<n;j++)
        {
            for(int k=0,x;k<n;k++)
            {
                if((!j&&!k)||(j==n-1&&k==n-1))
                {
                    putchar(48);
                    continue;
                }
                x=rand()%4;
                if(x)putchar(48);
                else putchar(49);
            }
            putchar(10);
        }
    }
    return 0;
}