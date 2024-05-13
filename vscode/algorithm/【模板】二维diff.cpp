#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3+9;

int a[N][N],d[N][N],d_[N][N];

void solve()
{
    int n,m,q;cin>>n>>m>>q;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>a[i][j];//输入矩阵
    
     for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            d[i][j] += a[i][j];
            d[i + 1][j] -= a[i][j];
            d[i][j + 1] -= a[i][j];
            d[i + 1][j + 1] += a[i][j];
        }//创建二维差分矩阵数组 化简公式 (动态规划？)

    //原理  首先我们可以对A进行一次行方向的差分运算，得到一个新的矩阵B，其中B[i][j]表示第i行相邻两列元素的差值（A[i][j] - A[i][j-1]）。接着，我们再对B进行一次列方向的差分运算，得到一个新的矩阵C，其中C[i][j]表示相邻两行相同列元素的差值（B[i][j] - B[i-1][j]）

    /*

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)d_[i][j] = a[i][j] - a[i][j-1];
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)d[i][j] = d_[i][j] - d_[i-1][j];  需要一个中间数组d_来存储B数组才能得到C  不能通过d本身求d的列差分数组

*/ 
    
    while(q--)
    {
        int x1,y1,x2,y2,c;cin>>x1>>y1>>x2>>y2>>c;
        d[x1][y1]+=c;
        d[x1][y2+1]-=c;
        d[x2+1][y1]-=c;
        d[x2+1][y2+1]+=c;
    } //进行修改操作

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            a[i][j] = a[i-1][j]+a[i][j-1]-a[i-1][j-1]+d[i][j],cout<<a[i][j]<<' '; //对差分数组进行前缀和还原修改后的a数组
        cout<<'\n';
    }



}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    while(_--)solve();
    system("pause");
    return 0;
}