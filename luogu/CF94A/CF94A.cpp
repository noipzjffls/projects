#include<cstdio>
char s[85],c[11][15],t[15];
bool check(char a[],char b[])
{
    for(int i=0;a[i];i++)if(a[i]-b[i])return 0;
    return 1;
}
int main()
{
    gets(s);
    for(int i=0;i<10;i++)gets(c[i]);
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<10;j++)t[j]=s[i*10+j];
        for(int j=0;j<10;j++)
        {
            if(check(t,c[j]))
            {
                printf("%d",j);
                break;
            }
        }
    }
}