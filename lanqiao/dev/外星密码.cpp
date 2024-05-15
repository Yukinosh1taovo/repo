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
				tmp = dfs(); // µÝ¹é
				while (n--)
				{
					str += tmp; // Æ´½Ó×Ö·û 
				} 
			}
			else if (x == ']')
			{
				return str; // ·µ»ØÖµ 
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
