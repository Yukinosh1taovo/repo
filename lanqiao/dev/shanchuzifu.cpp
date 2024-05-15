#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	char c;
	getline(cin, s);
	cin>>c;
	int p = s.find(c);
	while (p != string::npos)
	{
		s.erase(p,1);
		p = s.find(c);
	}
	cout<<s;
	return 0;
}
