#include<cstdio>
#include<cstdlib>
#define f()for(int i=0;i<9;i++)
int sudoku[9][9],cnt;
void print()
{
    f()
    {
        for(int j=0;j<9;j++)printf("%d ",sudoku[i][j]);
        putchar('\n');
    }
    printf("%d",cnt);
    exit(0);
}
int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=ch^48;
        ch=getchar();
    }
    return x;
}
bool check(int num,int pos)
{
    int row=pos/9,column=pos%9;
    f()if(i!=row&&sudoku[i][column]==num)return 0;
    f()if(i!=column&&sudoku[row][i]==num)return 0;
    for(int i=row/3*3;i<row/3*3+3;i++)for(int j=column/3*3;j<column/3*3+3;j++)if(i!=row&&j!=column&&sudoku[i][j]==num)return 0;
    return 1;
}
void dfs(int pos)
{
    int row=pos/9,column=pos%9;
    if(pos==81)print();
    if(sudoku[row][column])dfs(pos+1);
    else
    {
        for(int i=1;i<10;i++)
        {
            if(check(i,pos))
            {
                cnt++;
                sudoku[row][column]=i;
                dfs(pos+1);
                sudoku[row][column]=0;
            }
        }
    }
}
int main()
{
    f()for(int j=0;j<9;j++)sudoku[i][j]=read();
    dfs(1);
}