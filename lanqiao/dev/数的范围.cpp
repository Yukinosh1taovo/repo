#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, q;cin>>n>>q;
	multimap<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		int x;cin>>x;
		mp.insert({x, i});
	}
	while (q--)
	{
		int s;cin>>s;
		if (mp.lower_bound(s) != mp.end() && mp.lower_bound(s)->first == s)
		{
			
			if (mp.upper_bound(s) != mp.end())
				cout<< mp.lower_bound(s)->second << ' '<<mp.upper_bound(s)->second - 1<<'\n';
			
			else
			{
			cout << mp.lower_bound(s)->second << ' '<< n - 1<<'\n'; 
			}	
		}
		else
		{
			cout<<"-1 -1\n";	
		} 
		
	
	}
		return 0;
}
