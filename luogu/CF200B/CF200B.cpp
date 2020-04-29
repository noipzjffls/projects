#include<stdio.h>
int n,x,sum,tot;
int main()
{
    scanf("%d",&n);
    sum=n;
    while(n--)
    {
        scanf("%d",&x);
        tot+=x;
    }
    printf("%.6f",1.0*tot/sum);
}