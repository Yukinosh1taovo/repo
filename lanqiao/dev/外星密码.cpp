#include<bits/stdc++.h>

using namespace std;

int main()
{
	function<string()> dfs = [&]()
	{
		int n;
		string str = "", tmp;
		char x;
		while (cin >> x)
		{
			if (x == '[')
			{
				cin >> n;
				tmp = dfs(); // �ݹ�
				while (n--)
				{
					str += tmp; // ƴ���ַ� 
				} 
			}
			else if (x == ']')
			{
				return str; // ����ֵ 
			}
			else
			{
				str += x;
			}
		}
		return str;
	};
	
	cout << dfs() << '\n';
}
