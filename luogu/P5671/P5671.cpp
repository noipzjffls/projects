#include<bits/stdc++.h>
using namespace std;
int x,m,n;
double ans1[5],ans2[4];
int main()
{
    cin>>x>>m>>n;
    ans1[1]=(180-x)*0.5;
    ans1[2]=x*0.5;
    ans1[3]=x;
    ans1[4]=180-(x<<1);
    sort(ans1+1,ans1+5);
    for(int i=1;i<5;i++)
    {
        if(ans1[i]<=0||ans1[i]>180||ans1[i]==ans1[i-1])continue;
        cout<<ans1[i]<<" ";
    }
    putchar('\n');
    ans2[1]=sqrt(1ll*m*m+1ll*n*n);
    ans2[2]=sqrt(1ll*n*n-1ll*m*m);
    sort(ans2+1,ans2+3);
    for(int i=1;i<3;i++)
    {
        if(ans2[i]==0)continue;
        printf("%.5lf ",ans2[i]);
    }
    return 0;
}