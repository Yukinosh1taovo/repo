#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int today = 6;
    long long kil = 0;
    for (int year = 2000; year <= 2020; year++)
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
        
        if (year == 2020 && month == 10 && day == 2)
        {
        	cout<<kil;
			return 0; 
		}
        	
        
        if (today == 1 && day == 1)
        {
        	kil += 2;
        	today = today % 7 + 1;
        	continue;
		}
        
        if (today == 1)
		{
			kil += 2;
			today = today % 7 + 1;
			continue;
		}
        if (day == 1)
		{
			kil += 2;
			today = today % 7 + 1;
			continue;
		}
		
        kil += 1;
        today = today % 7 + 1;
        
        
    
	}	
	

    return 0;
}

