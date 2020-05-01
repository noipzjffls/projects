#include<cstdio>
#include<cmath>
#define dis(x_1,y_1,x_2,y_2)sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2))
int n,k,x[101],y[101];
double tot;
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
    n=read();
    k=read();
    for(int i=1;i<=n;i++)
    {
        x[i]=read();
        y[i]=read();
    }
    for(int i=1;i<n;i++)tot+=dis(x[i],y[i],x[i+1],y[i+1]);
    printf("%lf",tot*k*0.02);
}