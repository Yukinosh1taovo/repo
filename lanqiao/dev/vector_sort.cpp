#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin>>n;
	vector<vector<int>> ans(n);
	while(n--)
	{
		int len;cin>>len;
		while(len--)
		{
			int val;cin>>val;
			ans[n].push_back(val); 
		}
		sort(ans[n].begin(), ans[n].end());
	}
	sort(ans.begin(), ans.end());
	
	for (auto &nums : ans)
	{
		for (auto &num: nums)
			cout<< num<<' ';
		cout<<'\n';
	}
	return 0;
}
