#include<bits/stdc++.h>

using namespace std;

int n;
char a[1010][1010]; // 地图 
int vis[1010][1010] = {0}; // 判断是否搜过 
int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}}; //四个方向DFS 
int flag; // 标记这个岛是否被完全淹没  (只要岛上出现一块不会被淹没的地方 这座岛就不会被淹没)

void dfs(int x, int y)
{
	vis[x][y] = 1;
	
	if (a[x][y + 1] == '#' && a[x][y - 1] == '#' && a[x + 1][y] == '#' && a[x - 1][y] == '#') // 该地区四周都是陆地 
		flag = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + d[i][0], ny = y + d[i][1];
		if (vis[nx][ny] == 0 && a[nx][ny] == '#')
			dfs(nx, ny);  // 标记陆地 
	}
	
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin>>a[i][j];	// 输入地图 
		}	
	}
	
		int ans = 0;
		
		
		for (int i = 1; i <= n; i++)  // DFS 所有位置 
		{
			for (int j = 1; j<= n; j++)
			{
				if (a[i][j] == '#' && vis[i][j] == 0)
				{
					flag = 0;
					dfs(i, j);
					if (flag == 0)
						ans++;
				}
			}
		}
	 cout << ans << '\n';
	 return 0;
	
} 
