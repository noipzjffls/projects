#include<bits/stdc++.h>
bool a[1001][1001];
int type[]={0,0,0,0,1,1,1,2,2,2,2},datanum,rangen[][2]={{1,10},{1,200},{1,1000}},rangem[][2]={{1,5},{1,20},{1,100}};
int random(int a,int b)
{
    return (rand()%(b-a+1))+a;
}
char filename[][10]={"","1.in","2.in","3.in","4.in","5.in","6.in","7.in","8.in","9.in","10.in"};
int main()
{
    srand((time(NULL)));
    for(datanum=9;datanum<=9;datanum++)
    {
        freopen(filename[datanum],"w",stdout);
        memset(a,0,sizeof(a));
        int typenum=type[datanum],m=random(rangem[typenum][0],rangem[typenum][1]),n=random(rangen[typenum][0],rangen[typenum][1]),x,y,z;
        printf("%d %d",m,n);
        while(n--)
        {
            z=random(0,1);
            while(1)
            {
                x=random(1,m);
                y=random(1,m);
                if(!a[x][y])
                {
                    a[x][y]=1;
                    break;
                }
            }
            printf("\n%d %d %d",x,y,z);
        }
    }
}