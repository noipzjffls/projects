#include<bits/stdc++.h>
using namespace std;
map<char,int>piece;
int n,attack[6];
char board[9][9],king,kingx,kingy,name[]={'\0','R','B','Q','N','P'};  
namespace check
{
    bool pawn(int x,int y)
    {
        if(king=='K'&&(board[x+1][y-1]=='K'||board[x+1][y+1]=='K'))return 1;
        if(king=='k'&&(board[x-1][y-1]=='k'||board[x-1][y+1]=='k'))return 1;
        return 0;
    }
    bool rook(int x,int y)
    {
        for(int nx=x-1;nx;nx--)
        {
            if(nx==kingx&&y==kingy)return 1;
            if(board[nx][y]!='*')break;
        }
        for(int nx=x+1;nx<=8;nx++)
        {
            if(nx==kingx&&y==kingy)return 1;
            if(board[nx][y]!='*')break;
        }
        for(int ny=y-1;ny;ny--)
        {
            if(x==kingx&&ny==kingy)return 1;
            if(board[x][ny]!='*')break;
        }
        for(int ny=y+1;ny<=8;ny++)
        {
            if(x==kingx&&ny==kingy)return 1;
            if(board[x][ny]!='*')break;
        }
        return 0;
    }
    bool bishop(int x,int y)
    {
        for(int nx=x-1,ny=y-1;nx&&ny;nx--,ny--)
        {
            if(nx==kingx&&ny==kingy)return 1;
            if(board[nx][ny]!='*')break;
        }
        for(int nx=x-1,ny=y+1;nx&&ny<=8;nx--,ny++)
        {
            if(nx==kingx&&ny==kingy)return 1;
            if(board[nx][ny]!='*')break;
        }
        for(int nx=x+1,ny=y-1;nx<=8&&ny;nx++,ny--)
        {
            if(nx==kingx&&ny==kingy)return 1;
            if(board[nx][ny]!='*')break;
        }
        for(int nx=x+1,ny=y+1;nx<=8&&ny<=8;nx++,ny++)
        {
            if(nx==kingx&&ny==kingy)return 1;
            if(board[nx][ny]!='*')break;
        }
        return 0;
    }
    bool queen(int x,int y)
    {
        return rook(x,y)||bishop(x,y);
    }
    bool knight(int x,int y)
    {
        int dx[]={-2,-2,-1,-1,1,1,2,2},dy[]={-1,1,-2,2,-2,2,-1,1};
        for(int i=0;i<8;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx==kingx&&ny==kingy)return 1;
        }
        return 0;
    }
    bool check_piece(int x,int y)
    {
        switch(piece[board[x][y]])
        {
            case 1:return rook(x,y);
            case 2:return bishop(x,y);
            case 3:return queen(x,y);
            case 4:return knight(x,y);
            case 5:return pawn(x,y);
        }
    }
}
namespace program
{
    void init()
    {
        piece['R']=piece['r']=1;
        piece['B']=piece['b']=2;
        piece['Q']=piece['q']=3;
        piece['N']=piece['n']=4;
        piece['P']=piece['p']=5;
        cin>>n;
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
            {
                cin>>board[i][j];
                if(board[i][j]=='K'||board[i][j]=='k')
                {
                    king=board[i][j];
                    kingx=i;
                    kingy=j;
                }
            }
        }
        if(isupper(king))for(int i=1;i<=5;i++)name[i]-='A'-'a';
        for(int i=1;i<=8;i++)for(int j=1;j<=8;j++)if(isalpha(board[i][j])&&isupper(board[i][j])!=isupper(king)&&check::check_piece(i,j))attack[piece[board[i][j]]]++;
    }
    void print()
    {
        for(int i=1;i<=5;i++)
        {
            while(attack[i]--)
            {
                putchar(name[i]);
                putchar('+');
                putchar('\n');
            }
        }
    }
    void work()
    {
        init();
        print();
    }
}
int main()
{
    program::work();
    return 0;
}