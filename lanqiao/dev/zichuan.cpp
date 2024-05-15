#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string a,b;
	int s = 0, t;
	cin>>a>>b;
	t = a.find(b);
	while(t != string::npos)
	{
		s++;
		t = a.find(b, t + 1);
	}
	cout<<s;
	return 0;
}
