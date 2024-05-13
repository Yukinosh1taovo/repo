#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+9;

int a[N],c[N];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int j=1,k=0,ans=0; //j,k为双指针 双指针位置看情况，灵活运用 多练
    while(j<=n)
    {
        while(k<n&&!c[a[k+1]])
        {
            c[a[++k]]++;
            ans = max(ans,k-j+1);
        }
        c[a[j]]--;      
        j++;
    }
    cout<<ans<<'\n';
}   

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _;cin>>_;
    while(_--)solve();
    system("pause");
    return 0;
}