## $\color{red}\text{【搜索入门】资料}$

这里整理了一些有关【搜索入门】的资料，供大家使用。

### $\color{green}\text{博客入口}$

[入口$1$：个人博客](https://shenyouran.github.io/search/)

[入口$2$：洛谷博客](https://www.luogu.com.cn/blog/shenyouran/search)

### $\color{green}\text{题目汇总}$

[配套题单](https://www.luogu.com.cn/training/12262)

|题目|难度|来源|算法|
| :----------: | :----------: | :----------: | :----------: |
|[$\text{P1443 马的遍历}$](https://luogu.com.cn/problem/P1443)|$\color{FFC116}\text{普及/提高-}$|无|$\text{BFS}$|
|[$\text{P1135 奇怪的电梯}$](https://luogu.com.cn/problem/P1135)|$\color{FFC116}\text{普及/提高-}$|无|$\text{BFS}$|
|[$\text{P1019 单词接龙}$](https://luogu.com.cn/problem/P1019)|$\color{FFC116}\text{普及/提高-}$|$\texttt{NOIP2000}$|$\text{DFS+字符串处理}$|
|[$\text{U119869 迷宫}$](https://luogu.com.cn/problem/U119869)|$\color{FFC116}\text{普及/提高-}$|无|$\text{DFS+路径保存}$|
|[$\text{U119904 迷宫（加强版）}$](https://luogu.com.cn/problem/U119904)|$\color{FFC116}\text{普及/提高-}$|无|$\text{记忆化DFS+路径保存}$|
|[$\text{P2895 Meteor Shower}$](https://luogu.com.cn/problem/P2895)|$\color{FFC116}\text{普及/提高-}$|$\texttt{USACO2008}$|$\text{BFS}$|
|[$\text{P1825 Corn Maze}$](https://luogu.com.cn/problem/P1825)|$\color{52C41A}\text{普及+/提高}$|$\texttt{USACO2011}$|$\text{BFS}$|

### $\color{green}\text{源代码+模板汇总}$

将博客中出现的所有源代码+模板（伪代码）进行整理。

#### $\color{purple}\text{迷宫生成代码}$

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,range;
int main()
{
    srand(time(NULL));
    while(cin>>range)
    {
        n=rand()%range+1;
        m=rand()%range+1;
        printf("%d %d\n",n,m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(rand()&1)printf(". ");
                else printf("# ");
            }
            putchar('\n');
        }
    }
    return 0;
}
```

#### $\color{purple}\text{DFS模板}$

```cpp
void dfs(参数表)
{
    if(到达终点状态)
    {
        输出或保存结果;
        退出该层循环或整个程序;
    }
    for(拓展方式)
    {
    	if(该步合法)
        {
            修改、计算、标记;
            dfs(新的参数表);
            回溯;(可选)
        }
    }
}
```

#### $\color{purple}\text{BFS数组维护模板}$

```cpp
队列类型 q;//一般来说队列用q表示
int front=1,rear=1;//先定义头指针和尾指针，一开始一般都为1
while(front<=rear)
{
    队列类型 qf=q[front];//为了方便，可以保存头指针的队列元素
    for(拓展方式)
    {
        if(该步合法)
        {
            修改、计算、标记;
            q[++rear]=...;//入队
            if(到达终点状态)
            {
                进行重赋值或直接输出并退出;
            }
        }
    }
    front++;//头指针右移
}
```

#### $\color{purple}\text{BFS STL:queue维护模板}$

```cpp
queue<队列类型>q;
while(q.size())//只要队列中有元素就继续操作
{
    队列类型 qf=q.front();//q.front()为头指针元素
    q.pop();//直接弹出队头
    for(拓展方式)
    {
        if(该步合法)
        {
            修改、计算、标记;
            q.push(...);//入队
            if(到达终点状态)
            {
                进行重赋值或直接输出并退出;
            }
        }
    }
}
```

#### $\color{purple}\text{P1443 马的遍历 - Solution 1 (30分记忆化DFS代码)}$

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,sx,sy,ans[401][401],dx[]={-2,-2,-1,-1,1,1,2,2},dy[]={-1,1,-2,2,-2,2,-1,1};
bool vis[401][401];
void dfs(int x,int y,int step)
{
    if(step>ans[x][y])return;//剪枝
    ans[x][y]=step;//标记步数
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||ny<1||nx>n||ny>m||vis[nx][ny])continue;
        vis[nx][ny]=true;//标记访问
        dfs(nx,ny,step+1);//继续搜索
        vis[nx][ny]=false;//回溯
    }
}
int main()
{
    memset(ans,0x3f,sizeof(ans));//初始步数为无限大
    scanf("%d%d%d%d",&n,&m,&sx,&sy);
    ans[sx][sy]=0;//初始格子标记为0
    vis[sx][sy]=true;//初始格子标记访问
    dfs(sx,sy,0);//开始搜索
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(ans[i][j]==0x3f3f3f3f)printf("%-5d",-1);//判断是否能访问到
            else printf("%-5d",ans[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
```

#### $\color{purple}\text{P1443 马的遍历 - Solution 2 (100分BFS代码)}$

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,dx[]={-2,-2,-1,-1,1,1,2,2},dy[]={-1,1,-2,2,-2,2,-1,1},front=1,rear=1,ans[401][401];
//dx,dy为马的方向增量数组，头、尾指针定义为1，ans数组保存输出的矩阵
bool vis[401][401];//保存是否被访问过
struct node
{
    int x,y,step;
}q[160001];//用结构体当做队列元素
int main()
{
    scanf("%d%d%d%d",&n,&m,&q[1].x,&q[1].y);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans[i][j]=-1;//全部置为-1（即假设无法遍历到）
    ans[q[1].x][q[1].y]=0;//把开始坐标的答案置为0
    vis[q[1].x][q[1].y]=true;//标记开始坐标为访问过
    while(front<=rear)
    {
        node qf=q[front];
        for(int i=0;i<8;i++)
        {
            int nx=qf.x+dx[i],ny=qf.y+dy[i];
            if(nx<1||ny<1||nx>n||ny>m||vis[nx][ny])continue;
            q[++rear]=(node){nx,ny,qf.step+1};//入队
            ans[nx][ny]=q[rear].step;//ans数组赋值
            vis[nx][ny]=true;//标记访问
        }
        front++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)printf("%-5d",ans[i][j]);//注意格式化输出方式
        putchar('\n');
    }
    return 0;
}
```

#### $\color{purple}\text{P1335 奇怪的电梯 - Solution 1 (100分记忆化DFS代码)}$

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,a,b,k[201],ans[201];
//ans[i]保存到达第i层需要按按钮的次数
void dfs(int cur,int step)
{
    if(step>ans[cur])return;//剪枝
    ans[cur]=step;//把到达该楼层所需按按钮次数赋值为当前的step
    int dx[]={k[cur],-k[cur]};//增量数组
    for(int i=0,nx;i<2;i++)
    {
        nx=cur+dx[i];//即将到达的新楼层
        if(nx>n||nx<1)continue;//进行范围的判断
        dfs(nx,step+1);//下一层搜索继续
    }
}
int main()
{
    memset(ans,0x3f,sizeof(ans));
    //初始把按按钮次数赋值为无限大，默认都不能到达
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)scanf("%d",&k[i]);
    dfs(a,0);//开始搜索
    if(ans[b]==0x3f3f3f3f)puts("-1");//如果无法到达（即次数为无限大），则输出-1
    else printf("%d",ans[b]);//否则输出最少的次数
}
```

#### $\color{purple}\text{P1335 奇怪的电梯 - Solution 2 (100分BFS代码)}$

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,goal,front=1,rear=1,a[201];
bool vis[201];//标记当前楼层是否已经到达
struct node
{
    int floor,step;
}q[2001];
int main()
{
    scanf("%d%d%d",&n,&q[1].floor,&goal);
    if(goal==q[1].floor)//特判一定要注意！
    {
        putchar('0');
        return 0;
    }
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);//输入对应楼层按钮上的数字
    while(front<=rear)
    {
        node f=q[front];
        int d[]={a[f.floor],-a[f.floor]};
        /*
        方向增量数组：
        1. 向上a[f.floor]楼
        【前提条件】目标楼层小于等于n楼
        2. 向下a[f.floor]楼
        【前提条件】目标楼层大于0楼
        */
        for(int i=0;i<2;i++)
        {
            node r=(node){f.floor+d[i],f.step+1};
            //即将要入队的元素
            if(r.floor>n||r.floor<1||vis[r.floor])continue;
            //判断是否满足前提条件
            q[++rear]=r;//入队
            vis[r.floor]=true;//标记访问
            if(r.floor==goal)//判断是否到达目标楼层
            {
                printf("%d",r.step);
                return 0;
            }
        }
        front++;//头指针+1
    }
    puts("-1");//无法到达就输出-1
    return 0;
}
```

#### $\color{purple}\text{P1019 单词接龙 (100分DFS+字符串处理代码)}$

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,ans,t[21];//t数组保存使用次数
char ch;//保存开头字母
string s[21];//保存字符串
string transfer(string a,string b)//判断是否可以转换+如果可以就直接转换
{
    for(int i=0,j=a.size()-1;a[i]&&b[i];i++,j--)//新建两个指针，分别在b和a上
    {
        string na=a.substr(j),nb=b.substr(0,i+1);//取其子串
        if(na==nb&&na!=a&&nb!=b)return a+b.substr(i+1);//如果两子串相等且没有包含关系就可以拼接——直接返回拼接内容
    }
    return "ERROR";//因为正常情况没有大写字母，所以返回ERROR没有影响
}
void dfs(string cur)
{
    for(int i=1;i<=n;i++)
    {
        if(t[i]>1)continue;//已经使用过2次就不能再继续使用
        string ns=transfer(cur,s[i]);//把新拼接好的字符串赋值给ns
        if(ns=="ERROR")continue;//如果等于ERROR就说明无法拼接
        t[i]++;//使用次数加1
        dfs(ns);//继续深搜
        t[i]--;//回溯！
    }
    ans=max(ans,int(cur.size()));//取ans和当前字符串大小的最大值
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    cin>>ch;
    for(int i=1;i<=n;i++)
    {
        if(s[i][0]==ch)
        {
            memset(t,0,sizeof(t));//使用次数清零
            t[i]++;//该字符串开头已经使用了一次
            dfs(s[i]);//开始深搜
        }
    }
    cout<<ans;
    return 0;
}
```

#### $\color{purple}\text{U119869 迷宫 - Solution 1 (10分骗分代码})$

```cpp
#include<bits/stdc++.h>
int main()
{
    puts("-1");
    return 0;
}
```

#### $\color{purple}\text{U119869 迷宫 - Solution 2 (100分DFS+路径保存代码)}$

```cpp
#include<bits/stdc++.h>
using namespace std;
int m,n,x,y,dx[]={0,0,-1,1},dy[]={-1,1,0,0},route[401],maps[21][21];
//增量数组不必考虑顺序，因为有SPJ
bool vis[21][21];
void print(int k)
{
    cout<<"(1,1)";
    int a=1,b=1;//定义两个变量，用来输出路径
    for(int i=1;i<k;i++)
    {
        a+=dx[route[i]],b+=dy[route[i]];
        //每一次a和b加上增量数组对应的坐标
        cout<<"->("<<a<<','<<b<<')';
        //格式化输出
    }
    exit(0);//输出之后，退出整个程序
}
void dfs(int dep)
{
    if(x==n&&y==m)//如果到达了终点就是输出路径
    {
        print(dep);
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&nx<=n&&ny>0&&ny<=m&&!maps[nx][ny]&&!vis[nx][ny])
        {
            vis[nx][ny]=1;//标记访问
            x=nx,y=ny,route[dep]=i;
            //x和y赋值为新位置，然后路径数组设为i即可，表示增量的访问
            dfs(dep+1);//继续下层搜索
            vis[x][y]=0;//回溯
            x-=dx[i],y-=dy[i];//回溯
        }
    }
}
int main()
{
    scanf("%d",&n);
    m=n;//为了方便，定义一个变量m表示宽，使其等于n
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%1d",&maps[i][j]);
            /*
            注意输入方式！scanf百分号后加1d表示读入单字符的整型变量
            例如：
            输入为1239848
            scanf("%1d",&x)之后，x被赋值为1
            */
        }
    }
    vis[1][1]=true;//点(1,1)必须经过，所以这里直接标记访问
    x=y=1;//这里的x和y用作全局变量，表示当前的坐标，初始都为1
    dfs(1);//从第一层开始搜索
    puts("-1");//不能到达终点就输出-1
    return 0;
}
```

#### $\color{purple}\text{U119904 迷宫（加强版）- Solution 1 (10分DFS+路径保存代码)}$

```cpp
#include<bits/stdc++.h>
using namespace std;
int t,m,n,x,y,ans,dx[]={0,0,-1,1},dy[]={-1,1,0,0},route[401],r[401],maps[21][21];
bool vis[21][21],flag;
void print(int k)
{
    printf("(1,1)");
    int a=1,b=1;
    for(int i=1;i<=k;i++)
    {
        a+=dx[route[i]],b+=dy[route[i]];
        printf("->(%d,%d)",a,b);
    }
    putchar('\n');
}
void dfs(int dep,int step)
{
    if(step<ans&&x==n&&y==m)//如果到达终点而且步数更少就更新步数和路径，并标记可以走出迷宫
    {
        ans=step;
        flag=true;
        for(int i=1;i<=step;i++)route[i]=r[i];
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&nx<=n&&ny>0&&ny<=m&&!maps[nx][ny]&&!vis[nx][ny])
        {
            vis[nx][ny]=true;
            x=nx,y=ny,r[dep]=i;
            dfs(dep+1,step+1);
            vis[x][y]=false;
            x-=dx[i],y-=dy[i];
        }
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        flag=false;
        memset(vis,false,sizeof(vis));
        ans=0x3f3f3f3f;
        scanf("%d",&n);
        m=n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%1d",&maps[i][j]);
            }
        }
        vis[1][1]=true;
        x=y=1;
        dfs(1,0);
        if(flag)
        {
            printf("%d\n",ans);
            print(ans);
        }
        else puts("-1");
    }
    return 0;
}
```

#### $\color{purple}\text{U119904 迷宫（加强版） - Solution 2 (100分记忆化DFS+路径保存代码)}$

```cpp
#include<bits/stdc++.h>
using namespace std;
int t,m,n,x,y,ans[21][21],dx[]={0,0,-1,1},dy[]={-1,1,0,0},route[401],r[401],maps[21][21];
bool vis[21][21],flag;
void print(int k)
{
    printf("(1,1)");
    int a=1,b=1;
    for(int i=1;i<=k;i++)
    {
        a+=dx[route[i]],b+=dy[route[i]];
        printf("->(%d,%d)",a,b);
    }
    putchar('\n');
}
void dfs(int dep,int step)
{
    if(x==n&&y==m)
    {
        if(step<ans[x][y])//如果当前步数小于最少步数就执行
        {
            flag=true;//标记能走出迷宫
            ans[x][y]=step;//更新最短路径步数
            for(int i=1;i<=step;i++)route[i]=r[i];//更新最短的路径
        }
        return;
    }
    if(step>ans[x][y])return;//剪枝
    ans[x][y]=step;//更新最少步数
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&nx<=n&&ny>0&&ny<=m&&!maps[nx][ny]&&!vis[nx][ny])
        {
            vis[nx][ny]=true;
            x=nx,y=ny,r[dep]=i;
            dfs(dep+1,step+1);
            vis[x][y]=false;
            x-=dx[i],y-=dy[i];
        }
    }
}
int main()
{
    scanf("%d",&t);//输入数据组数
    while(t--)
    {
        flag=false;//flag判断是否能够走出迷宫
        memset(vis,false,sizeof(vis));//初始设定都未访问过
        memset(ans,0x3f,sizeof(ans));//初始设定到达对应位置的步数接近为无穷大
        scanf("%d",&n);//输入迷宫大小
        m=n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%1d",&maps[i][j]);
            }
        }
        vis[1][1]=true;
        x=y=1;
        dfs(1,0);
        if(flag)//如果能够走出迷宫就执行
        {
            printf("%d\n",ans[n][m]);//输出最少步数+换行
            print(ans[n][m]);//输出最短路径
        }
        else puts("-1");//无法到达终点就输出-1
    }
    return 0;
}
```

#### $\color{purple}\text{P2895 Meteor Shower - Solution 1 (63分记忆化DFS代码)}$

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,dx[]={0,-1,0,0,1},dy[]={0,0,-1,1,0},land[305][305],step[305][305],ans=0x3f3f3f3f;
bool vis[305][305];
void dfs(int x,int y,int t)
{
    if(t>step[x][y])return;//剪枝
    step[x][y]=t;//重新赋值
    if(land[x][y]==0x3f3f3f3f)//保存最小步数并剪枝
    {
        ans=min(t,ans);
        return;
    }
    for(int i=1;i<5;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0||ny<0||nx>304||ny>304||vis[nx][ny]||t+1>=land[nx][ny])continue;
        vis[nx][ny]=true;
        dfs(nx,ny,t+1);
        vis[nx][ny]=false;
    }
}
int main()
{
    memset(step,0x3f,sizeof(step));
    memset(land,0x3f,sizeof(land));
    cin>>n;
    for(int i=0,a,b,c;i<n;i++)
    {
        cin>>a>>b>>c;
        for(int i=0;i<5;i++)
        {
            int nx=a+dx[i],ny=b+dy[i];
            if(nx<0||ny<0||nx>304||ny>304)continue;
            land[nx][ny]=min(land[nx][ny],c);
        }
    }
    dfs(0,0,0);//开始搜索
    if(ans==0x3f3f3f3f)puts("-1");//无法到达就输出-1
    else printf("%d",ans);
    return 0;
}
```

#### $\color{purple}\text{P2895 Meteor Shower - Solution 2 (100分BFS代码)}$

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,dx[]={0,-1,0,0,1},dy[]={0,0,-1,1,0},front=1,rear=1,land[305][305],vis[305][305];
struct node
{
    int x,y,t;
}q[90005];
int main()
{
    memset(land,0x3f,sizeof(land));//land保存的是对应位置陨石下落的时间，初始假定都不下落，所以可以认为是接近无限大
    cin>>n;
    for(int i=0,a,b,c;i<n;i++)
    {
        cin>>a>>b>>c;//每次输入三个参数，表示(a,b)位置在c时间会掉落陨石
        for(int i=0;i<5;i++)//注意这里在[0,5)范围，因为0增量数组为(0,0)，包括当前位置
        {
            int nx=a+dx[i],ny=b+dy[i];
            if(nx<0||ny<0||nx>304||ny>304)continue;
            //注意！陨石只能在300以内掉落，但是可能会影响到更远的范围，用304是为了防止RE
            land[nx][ny]=min(land[nx][ny],c);//取掉落时间最小值
        }
    }
    while(front<=rear)
    {
        node qf=q[front];
        for(int i=1;i<5;i++)
        {
            int nx=qf.x+dx[i],ny=qf.y+dy[i];
            if(nx<0||ny<0||nx>304||ny>304||vis[nx][ny]||qf.t+1>=land[nx][ny])continue;
            /*
            满足下列情况的一种则不能继续拓展：
            1、出边界
            2、已经访问过
            3、该地已经被陨石影响
            */
            vis[nx][ny]=true;//标记访问
            q[++rear]=(node){nx,ny,qf.t+1};//入队
            if(land[nx][ny]==0x3f3f3f3f)//如果该地没有陨石降落就说明已经安全
            {
                printf("%d",q[rear].t);
                return 0;
            }
        }
        front++;
    }
    puts("-1");//不能到达安全的格子就输出-1
    return 0;
}
```

#### $\color{purple}\text{P1825 Corn Maze (100分BFS代码)}$

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,sx,sy,dx[]={-1,0,0,1},dy[]={0,-1,1,0},maps[301][301],front=1,rear=1;
/*
对于maps[i][j]：
终点：-1
障碍：-2
传送门：'A'~'Z'所对应的整型值
*/
bool vis[301][301];
struct node
{
    int x,y,step;
}q[90001];
void travel(int &x,int &y)//如果是传送门就可以进行传送，该函数实现了传送功能，即改变横纵坐标
{
    int temp=maps[x][y];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==x&&j==y)continue;//不能是相同的位置
            if(temp==maps[i][j])//判断两个传送门是否匹配
            {
                x=i;
                y=j;
                return;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char ch;
            cin>>ch;
            switch(ch)
            {
                case '=':
                {
                    maps[i][j]=-1;
                    break;
                }
                case '@':
                {
                    sx=i;
                    sy=j;
                    //对开始坐标进行赋值
                    break;
                }
                case '.':break;
                case '#':
                {
                    maps[i][j]=-2;
                    break;
                }
                default:maps[i][j]=ch;
            }
        }
    }
    vis[sx][sy]=true;//开始位置要标记访问
    q[1]=(node){sx,sy,0};//初始化
    while(front<=rear)
    {
        node t=q[front];//取队头
        for(int i=0;i<4;i++)
        {
            int nx=t.x+dx[i],ny=t.y+dy[i];
            if(nx>0&&ny>0&&nx<=n&&ny<=m&&maps[nx][ny]!=-2&&!vis[nx][ny])//判断该位置是否满足要求
            {
                vis[nx][ny]=true;//标记访问过
                if(maps[nx][ny]>0)travel(nx,ny);//如果是传送门就传送
                q[++rear]=(node){nx,ny,t.step+1};//入队
                if(maps[q[rear].x][q[rear].y]==-1)//如果是终点就可以结束了
                {
                    printf("%d",q[rear].step);
                    return 0;
                }
            }
        }
        front++;
    }
    return 0;
}
```

### $\color{green}\text{题单无注释AC代码链接汇总}$

感谢您用鼠标滑过了这么长的篇幅。~~适合复制粘贴的~~高清代码来了！

[P1443 马的遍历](https://shenyouran.github.io/projects/luogu/P1443/P1443.cpp)

[P1135 奇怪的电梯 DFS](https://shenyouran.github.io/projects/luogu/P1135/dfs.cpp)

[P1135 奇怪的电梯 BFS](https://shenyouran.github.io/projects/luogu/P1135/bfs.cpp)

[P1019 单词接龙](https://shenyouran.github.io/projects/luogu/P1019/P1019.cpp)

[U119869 迷宫](https://shenyouran.github.io/projects/luogu/U119869/std.cpp)

[U119904 迷宫（加强版）](https://shenyouran.github.io/projects/luogu/U119904/std.cpp)

[P2895 Meteor Shower](https://shenyouran.github.io/projects/luogu/P2895/P2895.cpp)

[P1825 Corn Maze](https://shenyouran.github.io/projects/luogu/P1825/P1825.cpp)