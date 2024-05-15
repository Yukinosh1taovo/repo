#include<bits/stdc++.h>

using namespace std;

int n;
char a[1010][1010]; // ��ͼ 
int vis[1010][1010] = {0}; // �ж��Ƿ��ѹ� 
int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}}; //�ĸ�����DFS 
int flag; // ���������Ƿ���ȫ��û  (ֻҪ���ϳ���һ�鲻�ᱻ��û�ĵط� �������Ͳ��ᱻ��û)

void dfs(int x, int y)
{
	vis[x][y] = 1;
	
	if (a[x][y + 1] == '#' && a[x][y - 1] == '#' && a[x + 1][y] == '#' && a[x - 1][y] == '#') // �õ������ܶ���½�� 
		flag = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + d[i][0], ny = y + d[i][1];
		if (vis[nx][ny] == 0 && a[nx][ny] == '#')
			dfs(nx, ny);  // ���½�� 
	}
	
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin>>a[i][j];	// �����ͼ 
		}	
	}
	
		int ans = 0;
		
		
		for (int i = 1; i <= n; i++)  // DFS ����λ�� 
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
