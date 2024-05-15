#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int cnt = 0;
	int n = str.size();
	for (int i = 0; i < n; i++)
	{
		if (str[i] != ' ')
			cnt++;
	}
	cout << cnt;
}
