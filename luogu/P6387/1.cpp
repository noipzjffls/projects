#include<cstdio>
int x,a[10],b[10];
int pow10(int x)
{
    int s=1;
    while(x--)s=(s<<3)+(s<<1);
    return s;
}
int f(int n,int check)
{
    int s=0;
    while(n)
    {
        if(check==1)b[n%10]++;
        else if(!check)a[n%10]++;
        s++;
        n/=10;
    }
    return s;
}
bool check()
{
    for(int i=0;i<10;i++)if(a[i]!=b[i])return 0;
    return 1;
}
void memset()
{
    for(int i=0;i<10;i++)b[i]=0;
}
int main()
{
    scanf("%d",&x);
    f(x,0);
    for(int i=x+1;i<pow10(f(x,-1));i++)
    {
        memset();
        f(i,1);
        if(check())
        {
            printf("%d",i);
            return 0;
        }
    }
    putchar('0');
}