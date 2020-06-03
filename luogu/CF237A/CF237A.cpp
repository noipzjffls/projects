#include<bits/stdc++.h>
using namespace std;
int n,a[24][60],ans;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main()
{
    scanf("%d",&n);
    while(n--)a[read()][read()]++;
    for(int i=0;i<24;i++)for(int j=0;j<60;j++)ans=max(ans,a[i][j]);
    printf("%d",ans);
    return 0;
}