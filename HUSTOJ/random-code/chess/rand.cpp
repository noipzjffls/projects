#include<bits/stdc++.h>
bool a[1001][1001];
int m,n,x,y,z;
int main()
{
    srand(unsigned(time(NULL)));
    m=rand()%100+1;
    n=rand()%1000+1;
    printf("%d %d",m,n);
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            x=rand()%m+1;
            y=rand()%m+1;
            z=rand()%2;
            if(!a[x][y])
            {
                a[x][y]=1;
                break;
            }
        }
        printf("\n%d %d %d",x,y,z);
    }
}