#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;

ll   a[N],d[N], p[N];  //包含数据修改 都开ll防止超限

void solve(int n)
{
    for(int i=1;i<=n;i++)d[i] = a[i] - a[i-1]; //创建差分数组

    int m;cin>>m;
    while(m--) //进行m次修改
    {
        int l,r,x;cin>>l>>r>>x;
        d[l]+=x;
        d[r+1]-=x;

    }

    for(int i=1;i<=n;i++)a[i]=a[i-1]+d[i];//对差分数组求前缀和 还原成修改后的a数组

    for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];//对a数组求前缀和数组p  以求数组a在区间l到r的和

    int q;cin>>q;
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<p[r]-p[l-1]<<'\n';  
        
    }
}


int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int _=1;
    while(_--)solve(n);

    system("pause");
    return 0;
}