#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	int n, m;cin >> n >> m;
	map<string, string> mp;
	
	while(n--)
	{
		string name;
		string num;
		cin>>name>>num;
		mp[name] = num;
	}
	
	while (m--)
	{
		int s; cin>>s;
		string str;cin>>str;
		
		if (s == 1)
		{
			if (mp.find(str) != mp.end())
			{
				cout<<mp[str];
			}
			else
			{
				cout<<"NO";
			}
		}
		if (s == 2)
		{
			if (str <= mp.begin()->first)
			{
				cout<<"NO";
			}
			else
			{
				auto it = mp.lower_bound(str);
				it--;
				cout<<it->second;
			}
		}
		if (s == 3)
		{
			if (str >= (--mp.end())->first)
			{
				cout<<"NO";
			}
			else
			{
				auto it = mp.upper_bound(str);
				cout<<it->second;
			}
			
		}
		cout<<'\n';
	}
	return 0;
}
