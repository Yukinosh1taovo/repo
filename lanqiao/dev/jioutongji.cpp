#include<bits/stdc++.h>

using namespace std;

int main()
{
	int x;
	int sum = 0, cnt = 0;
	while(true)
	{
		cin >> x;
		if (x == 0)
		{
			break;
		}
		if (x % 2 == 0)
			cnt++;
			
		if (x % 2 != 0)
		{
			sum += x;
		}
		
	}
	
	cout << cnt << '\n' << sum;
	return 0;
}
