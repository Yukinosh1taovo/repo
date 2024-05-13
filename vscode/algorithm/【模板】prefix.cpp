

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
int a[N]; //数据范围为-1e9到1e9 不超int
ll prefix[N]; //前缀和包含a1+a2+...+an 可能会超int
int main()
{
    //  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    int n;cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];

    for (int i = 1; i <= n; i++)prefix[i] = prefix[i - 1] + a[i];//前缀和数组

    int q;cin >> q;

    while (q--)
    {
        int l, r;cin >> l >> r;

        cout << prefix[r] - prefix[l - 1] << '\n';
    }
    system("pause");
    return 0;
}

/*
思路:创建一个prefix数组 prefix[i] = prefix[i-1] + a[i]
    即 a1 , a1+a2 , a1+a2+a3 , ... ,a1+a2+...+an

返回数组a在区间l,r的和即 prefix[r]-preifx[l-1]

每次询问仅需一次计算
    
*/