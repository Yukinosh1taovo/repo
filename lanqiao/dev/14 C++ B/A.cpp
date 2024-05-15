#include<bits/stdc++.h>

using namespace std;

int a[105];

int main()
{
	int ans = 0;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	for (int i = 0; i < 100; i++)
	{
		cin>>a[i];
	}
	 // 2 0 2 3 1 2 1 1 0 
	
	for (int year = 2023; year <= 2023; year++)
	for (int month = 1; month <= 12; month++)
	for (int day = 1; day <= 31; day++)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) ;
		else if (month == 2)
		{
			if (year % 4 == 0 && year % 100 != 0 || year %400 == 0)
			{
				if (day > 29) break;
			}
			else
			{
				if (day > 28) break;
			}
		}
		else
		{
			if (day > 30)
				break;
		}
		
		
		int arr[] = {2, 0, 2, 3, month / 10, month % 10, day / 10, day % 10};
		
		int cnt = 0, j = 0;
		
		for(int i = 0; i < 100; i++)
		{
			if (a[i] == arr[cnt])
			{
				cnt++;
			}
			if (cnt == 8)
			{
				ans++;
				break;
			}
		}
		
		
		
		
	}
	cout << ans;
	
	return 0;
 } 
