#include<bits/stdc++.h>

using namespace std;

int a[10] = {0,1,2,3,4,5,6,7,8,9};
int x, y;
int ans = 0;

int main()
{
	while (next_permutation(a + 1, a + 10))
	{
		x = a[4] * 100 + a[5] * 10 + a[6];
		y = a[7] * 100 + a[8] * 10 + a[9];
		
		if (a[1] * a[3] * y + a[2] * y + x * a[3] == 10 * a[3] * y)
			ans++;
	}
	cout<<ans;
	return 0; 
}
