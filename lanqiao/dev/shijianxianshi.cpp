#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ll time;cin >> time;
	
	long long h = time / 1000 / 3600 % 24;
	int m = time / 1000 % 3600 / 60;
	int s = time / 1000 % 3600 % 60;
	
	printf("%02d:%02d:%02d", h, m, s);
	
	return 0;
		
}
