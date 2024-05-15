#include <bits/stdc++.h>

using namespace std;



int main()
{
    int today = 6;
    int x = 1;
	for (int i = 0; i < 22; i++)
	{
		x = x * 20 % 7;
	 } 
	 
	 cout<< (today + x - 1) % 7 + 1;
}

