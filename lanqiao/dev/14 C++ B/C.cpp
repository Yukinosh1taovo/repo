#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;cin>>n;
	
	
	
	priority_queue<int> ans1; // �󶥶� 
	priority_queue<int,vector<int>,greater<int>> ans2; // С����  
	
	 // �� �󶥶ѣ� С���� 
	
	
	
	for (int i = 0; i < n; i++)
	{
		int x, y;cin>>x>>y;
		
		ans1.push(x / (y + 1) + 1);
		
		ans2.push(x / y);
		
	}
	
	cout << ans1.top() << ' '<< ans2.top()<<endl;
	
	
	

	
	
	return 0;	
}
