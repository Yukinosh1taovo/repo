#include<bits/stdc++.h>

using namespace std;

string s[100];

int main()
{
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s + n);
	for (auto &str : s)
	{
		cout<<str;
	}
	cout<<'\n';
	return 0;
	
}
