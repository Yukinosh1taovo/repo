#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	stringstream ss;
	int n, i, sum, a;
	cin>>n;
	getline(cin, s);
	for (i = 1; i <= n; i++)
	{
		getline(cin, s);
		ss.clear();
		ss.str(s);
		sum = 0;
		while(true)
		{
			ss>>a;
			if (ss.fail()) break;
			sum += a;
			
		}
		cout << sum << '\n';
	}
	return 0;
}
