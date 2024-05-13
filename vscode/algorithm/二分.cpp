#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+9;

int a[N];

void solve()
{
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    while(q--)
    {
        int x;cin>>x;
        int l=1,r=n;
        while(l+1!=r) 
        {
            int mid = (l+r)>>1; //>>1等价于/2向下取整 速度更快
            if(a[mid]>=x)r=mid; //注意>=与>的区别 前者取的是第一次出现的下标 后者取的是最后一次出现的下标 
            else l = mid;
        }
        if(a[r]==x)cout<<r<<' ';
        else cout<<-1<<' ';
    }


}


int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 

    int _=1;
    while(_--)solve();
    system("pause");
    return 0;
}