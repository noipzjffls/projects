#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int letter1[26],letter2[26];
int main()
{
    cin>>a>>b>>c;
    for(int i=0;a[i];i++)letter1[a[i]-'A']++;
    for(int i=0;b[i];i++)letter1[b[i]-'A']++;
    for(int i=0;c[i];i++)letter2[c[i]-'A']++;
    for(int i=0;i<26;i++)
    {
        if(letter1[i]!=letter2[i])
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}