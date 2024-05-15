#include<bits/stdc++.h>

using namespace std;

int main()
{
	
	int cnt = 0;
	string n;
	cin >> n;
	string str;
	while (cin >> str)
	{
		cnt += str.size();
	}
	
	cout << cnt;
	return 0;
}
