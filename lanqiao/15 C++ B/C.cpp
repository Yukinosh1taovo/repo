#include<bits/stdc++.h>

using namespace std;

int ans;
int a[20]; // 桶记录每一位的数字

int check(int x)
{
    int pos = 0;
    while (x)
    {
        a[++pos] = x % 10;
        x /= 10;
    }

    for (int i = 1; i <= pos; i++)
    {
        if (i % 2 != 0)  // 数位为奇数
        {
             if(a[i] % 2 == 0) return 0;
        }
        if (i % 2 == 0)
        {
            if (a[i] % 2 != 0) return 0;
        }
    }
    return 1;
    
}

int main()
{
    int n;cin>>n;

    for (int i = 1; i <= n; i++)
    {
        if (check(i)) ans++;
    }

    cout << ans<<'\n';
    system("pause");
    return 0;


}