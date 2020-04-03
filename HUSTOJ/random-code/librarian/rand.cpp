#include<bits/stdc++.h>
int n,q,m=1e7+1;
int main()
{
    srand(time(0));
    n=rand()%1001;
    q=rand()%1001;
    printf("%d %d",n,q);
    int a[n+1];
    for(int i=0;i<n;i++)a[i+1]=rand()%m;
    for(int i=1;i<=n;i++)printf("\n%d",a[i]);
    while(q--)
    {
        int digit=rand()%7+1,num,i=pow(10,digit-1),j=pow(10,digit)-1;
        if(digit==1)num=rand()%10;
        else num=rand()%(j-i+1)+i;
        printf("\n%d %d",digit,num);
    }
}