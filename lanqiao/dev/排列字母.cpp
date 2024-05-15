#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;cin>>s;
	map<char, int> mp;
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		mp[s[i]]++;
		
	}
	
	for (auto &c : mp)
	{
		for (int i = 0; i < c.second; i++)
		{
			cout<<c.first;
		}
	}
	return 0;
}
