#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+9;
int a[N];
int n,c;

int f(int mid)
{
int res=0,pre=-1e9;
for(int i=1;i<=n;i++)
if(a[i]-pre>=mid)
res++,pre=a[i];
return res;
}

void solve()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=0,r=1e9+10;
    while(l+1!=r)
    {
        int mid = (l+r)>>1;
        if(f(mid)>=c)l = mid;
        else r = mid;
    }
    cout<<l<<'\n';


}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    while(_--)
        solve();
    
    
    system("pause");
    return 0;
}