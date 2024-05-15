#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<string, int> mp;
	int n; cin>>n;
	while(n--)
	{
		string name;
		int age;
		cin>> name >> age;
		mp[name] = age;
	}
	
	for (auto &stu : mp)
	{
		cout<<stu.first<<' '<<stu.second<<endl;
	}
	return 0;
}
