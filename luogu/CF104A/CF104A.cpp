#include<cstdio>
int n;
int main()
{
    scanf("%d",&n);
    printf("%d",n<=10||n>=22?0:n==20?15:4);
}