#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int n;cin>>n;
	
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin>>nums[i];
	}
	
	vector<vector<int>> cnt(n,vector<int>());  // ��ά����cnt ��ʾ�� nums[i] �� ÿһ���������� 
	
	int ans = 1e5 + 9;
	
	for (int i = 0; i < n; i++)
	{
		cnt[i].push_back(nums[i]);
		
		for (int j = i + 1; j < n; j++)
		{	
			int k = nums[j]; // ����ߵ���λ 
			while(k / 10 != 0)
			{
				k /= 10;
			}
			
			int size_ = cnt[i].size() - 1;
			
			int t = cnt[i][size_] % 10;  //��ǰ�ߵ�ĩλ 
			
			if  (k == t)
			{
				cnt[i].push_back(nums[j]);
			}
			
		}
		int size_ = n - cnt[i].size();
		ans = min(ans, size_);
	}
	
	for (int i = 0; i < n; i++)
	{
	
	for (auto & num : cnt[i])
	{
		cout << num <<' ';
	}
	cout << endl;
	}
	
	
	cout<< ans;
	return 0;
}
