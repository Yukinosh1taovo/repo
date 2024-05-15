#include<bits/stdc++.h>

using namespace std;
// 直接找规律

// 1 5 13 25 41

// 1
// 1 + 4 = 5
// 1 + 4 + 8 = 13
// 1 + 4 + 8 + 12 = 25
// 1 + 4 + 8 + 12 + 16 = 41
 
int main()
{
	vector<int> arr(25);
	arr[1] = 1;
	for (int i = 2; i < 25; i++)
	{
		arr[i] = arr[i - 1] + 4 * (i - 1);
	} 
	
	cout<<arr[20];
	return 0;
}
