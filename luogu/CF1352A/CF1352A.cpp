#include<bits/stdc++.h>
using namespace std;
int t;
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0'||ch > '9')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int ans(int x)
{
    int s = 0;
    while (x)
    {
        s += bool (x % 10);
        x /= 10;
    }
    return s;
}
int pow10(int x,int p)
{
    while (p--) x = (x << 3) + (x << 1);
    return x;
}
int main()
{
    t = read();
    while (t--)
    {
        int k = read(), digit = 0;
        printf("%d\n", ans(k));
        while (k)
        {
            if(k % 10) printf("%d ", pow10(k % 10, digit));
            k /= 10;
            digit++;
        }
        putchar('\n');
    }
}