#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
vector<int> G[N]; // 埃氏筛法数组 存入每一个数的因子
vector<int> mk[N];

int H[N];


int main()
{
    for (int i = 1; i < N; i++)  // 埃氏筛法预处理
    for (int j = i; j < N; j += i)
        G[j].push_back(i);  // 存入因子

    int n; cin >> n; // 存入数据
    for (int i = 0; i < n; i++) cin >> H[i];

    sort(H, H + n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < G[H[i]].size(); j++) mk[G[H[i]][j]].push_back(H[i]);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (mk[i].size() >= 3)
        {
            cout << mk[i][0] << ' ' << mk[i][1] << ' ' << mk[i][2] << '\n'; 
            system("pause");
            return 0;
        }
    }
    system("pause");
    return 0;
    
}