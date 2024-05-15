#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;cin>>s;
	map<char, int> mp;
	for (int i = 0; i < s.size(); i++)
	{
		mp[s[i]]++;
	}
	
	int maxcnt = 0;
	for (auto &p : mp)
	{
		maxcnt = max(maxcnt, p.second);
	}
	
	for (auto &p : mp)
	{
		if (p.second == maxcnt)
			cout << p.first;
	}
	return 0;
}
