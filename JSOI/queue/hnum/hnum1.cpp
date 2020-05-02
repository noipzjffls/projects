#include<cstdio>
long long n,t,i;
int mark[]={2,3,5,7},j,x;
int main()
{
    scanf("%lld",&n);
    for(i=1;;i++)
    {
        t=i;
        for(j=0;j<4;j++)while(t%mark[j]==0)t/=mark[j];
        if(t==1)
        {
            if(++x==n)
            {
                printf("%lld",i);
                break;
            }
        }
    }
}
