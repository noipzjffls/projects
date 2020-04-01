#include<cstdio>
bool binary(int x)
{
    int i=0,j,a=0,b=0;
    while(x)
    {
        a+=x&1;
        b+=!(x&1);
        x>>=1;
    }
    return b>=a;
}
int l,r,s;
int main()
{
    scanf("%d%d",&l,&r);
    for(int i=l;i<=r;i++)s+=binary(i);
    printf("%d",s);
}