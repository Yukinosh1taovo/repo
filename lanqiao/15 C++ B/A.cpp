#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a = 0, b = 0;
    for (int i = 1; i <= 49; i++)
        a += i;

    for (int i = 1; i <= 6; i++)
        b += i;

    cout << a - b;
    system("pause");
    return 0;
}