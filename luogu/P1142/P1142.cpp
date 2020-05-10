#include<cstdio>
int n,point[701][2],maxp=-1;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&point[i][0],&point[i][1]);
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int p=2,X1=point[i][0],X2=point[j][0],Y1=point[i][1],Y2=point[j][1];
            if(X1==X2||Y1==Y2)continue;
            for(int k=j+1;k<=n;k++)
            {
                int X3=point[k][0],Y3=point[k][1];
                if(Y3*(X1-X2)==X3*(Y1-Y2)+X1*Y2-X2*Y1)p++;
            }
            if(p>maxp)maxp=p;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int p=2;
        for(int j=i+1;j<=n;j++)if(point[i][0]==point[j][0])p++;
        if(p>maxp)maxp=p;
    }
    for(int i=1;i<=n;i++)
    {
        int p=2;
        for(int j=i+1;j<=n;j++)if(point[i][1]==point[j][1])p++;
        if(p>maxp)maxp=p;
    }
    printf("%d",maxp);
    return 0;
}