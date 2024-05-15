#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;cin>>s;
	map<char, int> mp;
	int n = s.size(), maxcnt = 0;
	
	for (int i = 0; i < n; i++)
	{
		mp[s[i]]++;
		maxcnt = max(maxcnt, mp[s[i]]);
	}
	for (auto &p : mp)
	{
		if (p.second == maxcnt)
		{
		
			cout<<p.first<<'\n'<<p.second;
			break;
	}
	
}
return 0;
}
