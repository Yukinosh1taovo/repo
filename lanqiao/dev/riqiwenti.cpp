#include<bits/stdc++.h>

using namespace std;


bool check(int date) 
{

	
	int days[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int year = date /10000;
	int month = date % 10000 / 100;
	int day = date % 100;
		if (year > 2059 || year < 1960)	return false; // 年份不合法 
	
	if (month <= 0 || month > 12)	return false; // 月份不合法 
	
	else if (month == 2)  // 月份为2月 特判是否为闰年 
	{
		if (year % 4 == 0 && year / 100 != 0 || year % 400 == 0)  // 如果是闰年 
		{
			if (day > 29) return false;
		}
		else
		{
			if (day > days[2]) return false;
		}
	}
	else  // 月份为2月之外 
	{
		if (day > days[month]) return false;
	}
	
	return true;
}

int trans(int year, int month, int day) // 年 月 日 顺序 
{
	if (year > 59)
	{
		year = (1900 + year) * 10000;
	}
	else
	{
		year = (2000 + year) * 10000;
	}
	
	month = month * 100;
	
	return year + month + day;

}

int main()
{
	int num1, num2, num3;
	scanf("%d/%d/%d", &num1, &num2, &num3);
	
	
	
	set<int> st;
	 
	
	st.insert(trans(num1, num2, num3));
	st.insert(trans(num3, num1, num2));
	st.insert(trans(num3, num2, num1));
	
	for (auto &num : st)
	{
		if (check(num)) printf("%d-%02d-%02d\n", num/ 10000, num % 10000 / 100, num % 100);
	}
	
	


	
	return 0;
			
}
