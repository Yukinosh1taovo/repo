#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e4 + 10;

ll base = 1e9 + 1;

struct point
{
	 int x, y, r;
	 
}a[N];

ll getVal(int x, int y)
{
	return 1LL * x * base + y;
}

int getHash(ll x)
{
	int id = (x % MOD + MOD) % MOD;
	
	while (hash[id] != -1 && hash[id] != x)
	{
		++id;
		if (id == MOD) id = 0;
	}
	
	
}


int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n;i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].z;
	}	
	
	return 0;
}
