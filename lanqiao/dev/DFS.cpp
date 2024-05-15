#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, f[1001][1001], ans = 0;
char a[1001][1001];

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

void dfs(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > m || a[x][y] == '0') return ;   // ��Խ����ж��Ƿ�Ҫdfs �߽����� 
	
	a[x][y] = '0'; // ���Ϊ�߹� 


	dfs(x + 1, y); // �� �¡��ϡ��ҡ������dfs 
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
	cin >> n >> m; // n��m�� 
	
	memset(a, '0', sizeof(a));
	
	for (int i = 1; i <= n; i++) // ��1��ʼ���� ���㴦��Խ�� 
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
