#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;cin>>n;
	vector<int> score(n);
	for (int i = 0; i < n; i++)
	{
		int s;cin>>s;
		score[i] = s;
	}
	
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		int a;cin>>a;
		sum1 += score[i] * a;
	}
	for (int i = 0; i < n; i++)
	{
		int a;cin>>a;
		sum2 += score[i] * a;
	}
	if (sum1 > sum2)
	{
		cout << "ke";
		
	}
	if (sum1 < sum2)
	{
		cout<< "do";
	}
	if (sum1 == sum2)
	{
		cout << "same";
	}
}
