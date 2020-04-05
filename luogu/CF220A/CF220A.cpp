#include<cstdio>
#include<cstdlib>
int n,a[100001];
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
void swap(int &a,int &b)
{
    int p=a;
    a=b;
    b=p;
}
void check()
{
    for(int i=1;i<n;i++)if(a[i+1]<a[i])return;
    printf("YES");
    exit(0);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)a[i]=read();
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            swap(a[i],a[j]);
            check();
            swap(a[i],a[j]);
        }
    }
    printf("NO");
}