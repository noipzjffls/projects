#include<bits/stdc++.h>
using namespace std;
bool a[26];
int cnt;
int main()
{
    while(true)
    {
        char ch=getchar();
        if(ch=='\n')break;
        a[ch-'a']=true;
    }
    for(int i=0;i<26;i++)cnt+=a[i];
    if(cnt&1)puts("IGNORE HIM!");
    else puts("CHAT WITH HER!");
    return 0;
}