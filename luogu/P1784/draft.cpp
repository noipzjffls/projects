#include<cstdio>
#include<cstring>
#define f(x,y,z)for(int i=x;y;z)
#define F(x,y,z)for(int j=x;y;z)
const int maxr=729+100,maxc=324+100,maxn=maxr*maxc;
struct dancing_link
{
    int rcnt,ccnt,idx,left[maxn],right[maxn],up[maxn],down[maxn],row[maxn],col[maxn];
    int node_row[maxn],node_col[maxn];
    int answer,ans[maxr];
}dl;
void init(int n,int m)
{
    dl.right[m]=0;
    dl.left[0]=m;
    f(0,i<=m,i++)
    {
        dl.right[i]=i+1;
        dl.left[i]=i-1;
        dl.up[i]=dl.down[i]=i;
    }
    memset(dl.node_row,0,sizeof(dl.node_row));
    memset(dl.node_col,0,sizeof(dl.node_col));
    dl.idx=m+1;
}
void insert(int Row,int Col)
{
    dl.node_col[Col]++;
    dl.row[dl.idx]=Row;
    dl.col[dl.idx]=dl.up[dl.idx]=Col;
    dl.down[dl.idx]=dl.down[Col];
    dl.up[dl.down[Col]]=dl.down[Col]=dl.idx;
    if(!dl.node_row[Row])dl.node_row[Row]=dl.right[dl.idx]=dl.left[dl.idx]=dl.idx;
    else
    {
        dl.right[dl.idx]=dl.node_row[Row];
        dl.left[dl.idx]=dl.left[dl.node_row[Row]];
        dl.right[dl.left[dl.node_row[Row]]]=dl.idx;
        dl.left[dl.node_row[Row]]=dl.idx;
    }
    dl.idx++;
}
void remove(int Col)
{
    dl.right[dl.left[Col]]=dl.right[Col];
    dl.left[dl.right[Col]]=dl.left[Col];
    f(dl.down[Col],i!=Col,i=dl.down[i])
    {
        F(dl.right[i],j!=i,j=dl.right[j])
        {
            dl.up[dl.down[j]]=dl.up[j];
            dl.down[dl.up[j]]=dl.down[j];
            dl.node_col[dl.col[j]]--;
        }
    }
}
void resume(int Col)
{
    f(dl.up[Col],i!=Col,i=dl.up[i])
    {
        F(dl.left[i],j!=i,j=dl.left[j])
        {
            dl.up[dl.down[j]]=dl.down[dl.up[j]]=j;
            dl.node_col[dl.col[j]]++;
        }
    }
    dl.right[dl.left[Col]]=dl.left[dl.right[Col]]=Col;
}
bool dance(int depth)
{
    if(!dl.right[0])
    {
        dl.answer=depth;
        return 1;
    }
    int c=dl.right[0];
    f(dl.right[0],i,i=dl.right[i])if(dl.node_col[i]<dl.node_col[c])c=i;
    remove(c);
    f(dl.down[c],i!=c,i=dl.down[i])
    {
        dl.ans[depth]=dl.row[i];
        F(dl.right[i],j!=i,j=dl.right[j])remove(dl.col[j]);
        if(dance(depth+1))return 1;
        F(dl.left[i],j!=i,j=dl.left[j])resume(dl.col[j]);
    }
    resume(c);
    return 0;
}
char s[90],path[90];
struct node
{
    int r,c,v;
}NODE[maxr];
int main()
{
    
}
