#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	
	int n = str.size();
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ' || str[i] != ' ')
			cout<<str[i];
	}
	return 0;
}
