#include<bits/stdc++.h>

using namespace std;

int a[105][105];

int main()
{
	memset(a, 0, sizeof(a));
	
	int num = 1; // 要填入的数 
	int m, n;cin>>m>>n; //矩阵规模 
	int x = 0, y = n - 1; // 初始化坐标 
	a[x][y] = num;
	while (num < m * n)
	{	
		while (x + 1 <= m - 1 && !a[x + 1][y])	a[++x][y] = ++num; // 从上往下
		
		while (y - 1 >= 0 && !a[x][y - 1])	a[x][--y] = ++num; // 从右往左
		
		while (x - 1 >= 0 && !a[x - 1][y]) a[--x][y] = ++num; // 从下往上
		
		while (y + 1 <= n - 1 && !a[x][y + 1])	a[x][++y] = ++num; // 从左往右 
		
		 
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
		cout<<'\n';
	}
	return 0;
	
	
	
}
