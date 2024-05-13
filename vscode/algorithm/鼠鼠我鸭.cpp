#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+9;

ll a[N],w[N],p[N];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]; //1为鸭0为鼠
    for(int i=1;i<=n;i++)cin>>w[i];//输入体重

    ll sum=0;
    for(int i=1;i<=n;i++)
    if(a[i])sum+=w[i]; //计算未修改时鸭的体重总和

    for(int i=1;i<=n;i++)p[i] = p[i-1] + (a[i]?-1:1)*w[i]; //前缀和数组计算改变区间 1到i的动物种类 对sum的体重变化量 fix

ll fix=0,min_=0;
for(int i=1;i<=n;i++)
{
    fix = max(fix,p[i]-min_); //遍历计算出区间 l到r fix最大值
    min_ = min(min_,ll(p[i])); //遍历计算出 区间1到l fix最小值
}

cout<<sum+fix<<'\n';

}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;cin>>T;
    while(T--)solve();

    system("pause");
    return 0;
}