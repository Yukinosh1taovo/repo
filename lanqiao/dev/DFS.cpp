#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, f[1001][1001], ans = 0;
char a[1001][1001];

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

void dfs(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > m || a[x][y] == '0') return ;   // 防越界和判定是否要dfs 边界条件 
	
	a[x][y] = '0'; // 标记为走过 


	dfs(x + 1, y); // 对 下、上、右、左进行dfs 
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);	
	
	/*
	for (int i = 0; i < 4; i++)
	{
		new_x = x + dx[i];
		new_y = y + dy[i];
		dfs(new_x, new_y);
	}
	
	*/
}

int main()
{
	cin >> n >> m; // n行m列 
	
	memset(a, '0', sizeof(a));
	
	for (int i = 1; i <= n; i++) // 从1开始输入 方便处理越界 
	for (int j = 1; j <= m; j++)
		cin>>a[i][j];	
		
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		if (a[i][j] == '1')
		{
			ans++;
			dfs(i, j);	
		}	
	} 
	cout << ans;
	return 0;
} 
