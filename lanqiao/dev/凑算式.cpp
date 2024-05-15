#include<bits/stdc++.h>

using namespace std;

bool st[15]; // 标记数字是否被使用
int num[15], ans;  // num存储排列数字 

void dfs(int n)
{
	if (n == 10)
	{
		int x = num[4] * 100 + num[5] * 10 + num[6];
		int y = num[7] * 100 + num[8] * 10 + num[9];
		if (num[1] * num[3] * y + num[2] * y + x * num[3] == 10 * num[3] * y)
		{
			ans++;
			return;
		}
	}

	
	
	for (int i = 1; i <= 9; ++i)
	{
		if (st[i]) continue;
		st[i] = 1;
		num[n] = i;
		dfs(n + 1);
		st[i] = 0; // 回溯 
	}
}

int main()
{
	dfs(1);
	cout << ans;
	return 0;
}
