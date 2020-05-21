#include<bits/stdc++.h>
using namespace std;
stack<char>s;
int main()
{
    while(1)
    {
        char ch=getchar();
        if(ch=='(')s.push(ch);
        else if(ch==')')
        {
            if(!s.empty())s.pop();
            else
            {
                printf("No");
                return 0;
            }
        }
        else break;
    }
    if(s.empty())printf("Yes");
    else printf("No");
}