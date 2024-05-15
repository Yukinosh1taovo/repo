#include <bits/stdc++.h>

using namespace std;

int main()
{

    int cnt = 0;
    string n;
    getline(cin, n);
    string str;
    getline(cin, str);

    int t = stoi(n);
    for (int i = 0; i < t; i++)
    {
        if (str[i] != ' ')
            cnt++;
    }
    cout << cnt;
    system("pause");
    return 0;
}