#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+9;

int c[N];

void solve()
{
    int n,x;cin>>n;
    for(int i=1;i<=n;i++)cin>>x,c[x]++; //经典桶排序

    for(int i=0;i<N;i++) //注意i<N 不要数组越界
        while(c[i]!=0)
        {
            cout<<i<<' ';
            c[i]--;
        }
cout<<'\n';
}


int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 

    int _=1;
    while(_--)solve();
    system("pause");
    return 0;
}