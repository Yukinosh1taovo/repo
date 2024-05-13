#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e4 + 10;
const int MOD = 1e6 + 10;


ll base = 1e9 + 1;

struct point
{
    int x, y, r;
} a[N], b[N];

ll hs[MOD];


int bk[MOD], mk[MOD];

ll getVal(int x, int y)
{
    return 1LL * x * base + y;
}

int getHash(ll x)  
{
    int id = (x % MOD + MOD) % MOD;

    while (hs[id] != -1 && hs[id] != x)
    {
        ++id;
        if (id == MOD)  id = 0;
    }
    return id;
}

bool checkDis(int x1, int y1, int x2, int y2, int r)
{
    return 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2) <= r * r;
}

void explode(int x, int y, int r)
{
    for (int i = x - r; i <= x + r; i++)
    for (int j = y - r; j <= y + r; j++)
    {
        ll val = getVal(i, j);
        int id = getHash(val);
        if (bk[id] && checkDis(i, j, x, y, r) && !mk[id])
        {
            mk[id] = 1;
            explode(i, j, a[bk[id]].r);
        }
    }
}


int main()
{
    memset(hs, -1, sizeof(hs));
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].r;
        ll val = getVal(a[i].x, a[i].y);
        int num = getHash(val);
        hs[num] = val;
        if (!bk[num]) bk[num] = i;
        else if(a[i].r > a[bk[num]].r) bk[num] = i;

    }
        for (int i = 1; i <= m; i++) cin >> b[i].x >> b[i].y >> b[i].r;

        for (int i = 1; i <= m; i++) explode(b[i].x, b[i].y, b[i].r);

        for (int i = 1; i <= n; i++)
        {
            ll val = getVal(a[i].x, a[i].y);
            int num = getHash(val);
            if (mk[num]) ++ans;

        }
        cout << ans;
    system("pause");
    return 0;
}