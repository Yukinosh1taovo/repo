#include<bits/stdc++.h>

using namespace std;

bool check(int num)
{
	while (num != 0)
	{
		if (num % 10 == 2 || num % 10 == 4)
			return false;
			
		num /= 10;
	}
	return true;
}

int main()
{
	int n;cin>>n;
	
	long long ans = 0; 
	for (int i = 1; i <= n - 2; i++)
	for (int j = 1; j <= n - i - 1; j++)
	{
		int k = n - i - j;
		
		if (check(i) && check(j) && check(k))
		{
			if (i < j && j < k)
				ans++;	
		}

	}

	cout<<ans;
	
}
