#include<bits/stdc++.h>

using namespace std;

int a[105] = {5,6,8 ,6, 9, 1, 6, 1 ,2 ,4 ,9 ,1 ,9 ,8, 2 ,3, 6, 4 ,7 ,7, 5 ,9, 5 ,0 ,3 ,8, 7 ,5 ,8 ,1 ,5 ,8 ,6 ,1 ,8 ,3 ,0 ,3 ,7 ,9, 2,

7, 0 ,5 ,8 ,8 ,5, 7, 0, 9, 9, 1 ,9, 4, 4, 6, 8, 6 ,3 ,3 ,8 ,5 ,1 ,6 ,3 ,4 ,6, 7 ,0 ,7 ,8 ,2 ,7, 6 ,8 ,9 ,5 ,6 ,5, 6, 1, 4, 0, 1, 0, 0 ,9, 4, 8, 0, 9, 1, 2, 8, 5, 0 ,2, 5, 3, 3};

int main()
{
    int flag = 0;
    int cnt = 0;
    for (int year = 2023; year <= 2023; year++)
        for (int month = 1; month <= 12; month++)
            for (int day = 1; day <= 31; day++)
            {
                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                    ;
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
                
                int date[] = {2, 0, 2, 3, month / 10, month % 10, day / 10, day % 10};
                int j = 0;
                
                for (int i = 0; i < 100; i++)
                {
                	if (a[i] == date[j])
                	{
                		j++;
					}
					if (j == 8)
					{
						cnt++;
						break;
					}
				}
                
                
                        }
                        cout << cnt;

    return 0;
}

