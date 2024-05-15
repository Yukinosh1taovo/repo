#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, ans = 0;
char a[1001][1001]; // 存储搜索地图 

struct node   // 或者用pair<int, int> pr;
{
	int x, y; 
}

queue<node> q; // 队列存储广搜坐标 

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y)
{
	q.push({x,y});
	a[x][y] = '0'; // 标记为已访问 
	while (!q.empty())
	{
		node t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int new_x = t.x + dx[i];
			int new_y = t.y + dy[i];
			if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= n && a[new_x][new_y] == '1')
			{
				q.push({new_x, new_y});
				a[new_x][new_y] == '0'; // 标记为已访问
				 
			}
		}	
	}	 
	
} 




int main()
{
	cin >> n >> m;
	memset(a, '0', sizeof(a));
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		cin >> a[i][j]; // 输入搜索地图
		
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		if (a[i][j] == '1')
		{
			ans++;
			bfs(i, j);
		}
	 } 
		
		 
	
	return 0;
}
