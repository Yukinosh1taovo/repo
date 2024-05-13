#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+9;

vector<int> a; //vector数组容器
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x); //输入用push_back
    }

    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end()); //排序去重大法

    for(auto &i :a)
        cout<<i<<' ';

}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _=1;
    while(_--)solve();
    system("pause");
    return 0;
}