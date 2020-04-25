#include<cstdio>
bool cup[]={0,1,0,0};
char s[51];
void swap(bool &x,bool &y)
{
    bool t=x;
    x=y;
    y=t;
}
int main()
{
    while(char ch=getchar())
    {
        if(ch=='\n')break;
        switch(ch)
        {
            case 'A':
            {
                swap(cup[1],cup[2]);
                break;
            }
            case 'B':
            {
                swap(cup[2],cup[3]);
                break;
            }
            case 'C':swap(cup[1],cup[3]);
        }
    }
    for(int i=1;i<4;i++)if(cup[i])putchar(i+'0');
}