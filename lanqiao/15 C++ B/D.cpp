#include<bits/stdc++.h>

using namespace std;

string add(string a, string b) // 模拟字符串数字自加
{
    int flag = 0; // 模拟进位
    string ans;

    if (b == "1")
    {
        for (int i = 1; i < a.size(); i++)
        {
            b.push_back('0');
        }        
        reverse(b.begin(), b.end());
    }


    for (int i = a.size() - 1; i >= 0; i--)
    {
        int val = a[i] - '0' + b[i] - '0' + flag;
        if (val >= 10) val %= 10, flag = 1;
        else flag = 0;

        ans.push_back(char(val + '0'));
    }

    if (flag) ans.push_back('1');

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int n; cin >> n; // pow(2, n)
    string d; cin>> d; // 浮点数d

    int pos = 0;

    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] == '.')
        {
            pos = d.size() - i - 1;
            break;
        }
    }

    string x;

    for (auto ch : d)
    {
        if(ch != '.') x.push_back(ch);
    }

    for (int i = 0; i < n; i++)
        x = add(x, x);


    string xx;
    for (int i = 0; i < x.size() - pos; i++) xx.push_back(x[i]); // 取出整数位

    char check = x[x.size() - pos]; // 判定四舍五入

    if (check >= '5')
    {
        xx = add(xx, "1");
        cout << xx << '\n';
    }
    else cout << xx << '\n';
        


    system("pause");
    return 0;

}