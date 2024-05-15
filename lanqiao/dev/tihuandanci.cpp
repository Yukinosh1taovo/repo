#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;cin>>s;
	
	int p = s.find("black");
	
	while (p != string::npos)
	{
		s.replace(p,5, "block");
		p = s.find("black", p + 1);
	}
	cout<<s;
	return 0;
}
