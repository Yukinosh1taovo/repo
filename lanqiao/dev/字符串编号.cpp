#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str;cin>>str;
	int n = str.size();
	
	vector<int> arr;
	
	for (int i = 0; i < n - 1;)
	{
		int num = (str[i] - '0') * 10 + (str[i + 1] - '0');
		if (num >= 1 && num <= 26)
		{
			arr.push_back(num);
			i += 2;
		}
		else
		{
			arr.push_back(str[i] - '0');
			i++;
		}
	}
	int num_rear = (str[n - 2] - '0') * 10 + str[n - 1] - '0';
	int flag = (num_rear >= 1 && num_rear <= 26);
	if (!flag)
	{
		arr.push_back(str[n - 1] - '0');
	}
	for (auto &num : arr)
	{
		cout<<char('A' + num - 1);
	}
	return 0;
	
} 
