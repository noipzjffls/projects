#include<cstdio>
int id,a[10],b[10],letter[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9},times[]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
char s[101],temp;
int find(int x)
{
    for(int j=1;j<9;j++)if(a[j]==x)return j;
    return 9;
}
int main()
{
    for(int i=1;i<10;i++)scanf("%d",&a[i]);
    for(int i=1;i<10;i++)b[i]=find(i);
    getchar();
    gets(s);
    for(int i=0;s[i];i++)
    {
        id=letter[s[i]-'a'];
        if(b[id]==temp)putchar('#');
        for(int j=0;j<times[s[i]-'a'];j++)putchar(b[id]+'0');
        temp=b[id];
    }
}