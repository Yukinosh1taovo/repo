#include <bits/stdc++.h>

using namespace std;

int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int date)  // 判断枚举日期是否合法 
{
	int year = date / 10000;
	int month = date % 10000 / 100;
	int day = date % 100;
	
	if (month <= 0 || month > 12)
		return false;
	
	if (month != 2 && day > months[month] || day <= 0)
		return false;
		
		if (month == 2)
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				if (day > 29)
					return false;
			}
			else
			{
				if (day > 28)
					return false;
			}
			return true;
		}
		return true;
}



bool check1(string s)  // 判断回文数 
    {
    	int n = s.size();
    	for (int i = 0, j = n - 1; i < j; i++, j--)
    	{
    		if (s[i] != s[j])
    			return false;
    
		}
		return true; 
	}
	
	bool check2(string s) // 判断ABABBABA型 
	{
		if (check1(s))
		{
			if (s[0] != s[2] || s[1] != s[3] || s[0] == s[1])
				return false;
			
			return true;
		}
		return false;
	} 

int main()
{
    int date;cin>>date;
    bool flag = false;
    for (int i = date + 1; ; i++)
	{
		if (check(i))
		{
			string s = to_string(i);
			if (check1(s) && !flag)
			{
				cout<<s<<'\n';
				flag = true;
			}
			if (check2(s))
			{
				cout << s;
				break;
			}
		
		
		
			
		}
	} 
    		


    return 0;
}

