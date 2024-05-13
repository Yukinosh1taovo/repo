#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3+9;

ll a[N][N],p[N][N];
void solve()
{
    int n,m,q;cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>a[i][j];
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)p[i][j] = p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j]; //创建二维前缀和数组 化简公式 (动态规划？)

        

    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1]<<'\n';
    }
    
//原理 首先我们可以对A进行一次行方向的前缀和运算，得到一个新的矩阵B，其中B[i][j]表示第i行前j列所有元素的和。接着，我们再对B进行一次列方向的前缀和运算，得到一个新的矩阵C，其中C[i][j]表示前i行前j列所有元素的和
/*

for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)p[i][j] = p[i][j-1]+a[i][j];
for(int j=1;j<=m;j++)
    for(int i=1;i<=n;i++)p[i][j] = p[i-1][j]+a[i][j];

*/


}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    while(_--)solve();
    system("pause");
    return 0;
}