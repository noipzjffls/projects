#include<bits/stdc++.h>
using namespace std;
int a[100],len,m;
int main()
{
    while(scanf("%1d",&a[++len])!=EOF);
    len--;
    if(len%3)
    {
        m=3-len%3;
        for(int i=len;i;i--)a[i+m]=a[i];
        for(int i=1;i<=m;i++)a[i]=0;
    }
    for(int i=1,x;i<=len+m;i+=3)
    {
        x=(a[i]<<6)+(a[i]<<5)+(a[i]<<2)+(a[i+1]<<3)+(a[i+1]<<1)+a[i+2];
        switch(x)
        {
            case 0:putchar('0');break;
            case 1:putchar('1');break;
            case 10:putchar('2');break;
            case 11:putchar('3');break;
            case 100:putchar('4');break;
            case 101:putchar('5');break;
            case 110:putchar('6');break;
            case 111:putchar('7');break;
            default:puts("I love Luogu!");
        }
    }
}