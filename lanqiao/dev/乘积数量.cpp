#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ll n, s = 0;
	
	cin>>n;
	for (ll a = 1; a * a * a <= n; a++)
	{
		for (ll b = a; a * b * b <= n; b++)
		{
			if (b <= n / (a * b))  // b <= c
				s += (n / (a * b) - b + 1);      // c的取值为 [b, n/(a*b)]  s += 区间长度 
		}
	}
	cout << s;
}
