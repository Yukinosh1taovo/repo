#include<bits/stdc++.h>

using namespace std;

int main(){

	char str[15];
	int  cnt = 0;
	for (int year = 2022; year <= 2022; year++)
	for (int month = 1; month <= 12; month++)
	for (int day = 1; day <= 31; day++)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) ;
		else if (month == 2)
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				if (day > 29)
					break; 
			}
			else
			{
				if (day > 28)
					break;
			}
		}
		else
		{
			if (day > 30)
				break;
		}
		
		sprintf(str, "%d%02d%02d", year, month, day);
		
		for (int k = 4; k + 2 <= 7; k++)
		{
			if (str[k + 1] - str[k] == 1 && str[k + 2] - str[k + 1] == 1)
			{
			puts(str);
			cnt++;
		 	break;
			}	
		}
		
	}
	cout << cnt;
} 
