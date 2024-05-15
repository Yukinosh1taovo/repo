	#include<bits/stdc++.h>
	
	using namespace std;
	using ll = long long;
	
	
	
	int main()
	{
		int n,m;cin>>n>>m;
		vector<vector<int>> ans(n + 1);
		while(m--)
		{
			int x, y;cin>>x>>y;
			ans[x].push_back(y);
		}
		
		for (int i = 1; i <= n; i++)
		{
			cout<<ans[i].size()<<' ';
			sort(ans[i].begin(), ans[i].end());
			for (auto &num : ans[i])
			{
				cout << num<<' ';
			}
			cout<<'\n';
		}
		
		return 0;
	}
