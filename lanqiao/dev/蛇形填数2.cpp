#include<bits/stdc++.h>

using namespace std;

int a[105][105];

int main()
{
	memset(a, 0, sizeof(a));
	
	int num = 1; // Ҫ������� 
	int m, n;cin>>m>>n; //�����ģ 
	int x = 0, y = n - 1; // ��ʼ������ 
	a[x][y] = num;
	while (num < m * n)
	{	
		while (x + 1 <= m - 1 && !a[x + 1][y])	a[++x][y] = ++num; // ��������
		
		while (y - 1 >= 0 && !a[x][y - 1])	a[x][--y] = ++num; // ��������
		
		while (x - 1 >= 0 && !a[x - 1][y]) a[--x][y] = ++num; // ��������
		
		while (y + 1 <= n - 1 && !a[x][y + 1])	a[x][++y] = ++num; // �������� 
		
		 
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
