/*
User: shenyouran
Problem: 2138
Algorithm: Binary Tree, DFS
Language: C/C++
Record ID: 75259
Submit Time: 2020-10-31 15:35:12
*/
#include<stdio.h>
char a[101],b[101];
int l;
void f(int a1,int b1,int c1,int d1)
{
    if(a1>b1||c1>d1)return;
    int i;
    for(i=a1;i<=b1;i++)if(a[i]==b[c1])break;
    f(a1,i-1,c1+1,c1+i-a1);
    f(i+1,b1,c1+i-a1+1,d1);
    putchar(a[i]);
}
int main()
{
    scanf("%s%s",b,a);
    for(l=0;b[l];l++);
    f(0,l-1,0,l-1);
    return 0;
}