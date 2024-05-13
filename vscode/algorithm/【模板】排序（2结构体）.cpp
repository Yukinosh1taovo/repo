#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+9;

struct book 
{
    int a,b,c;
    bool operator < (const book &u)const
    {
        if(a==u.a&&b==u.b)return c<u.c;
        if(a==u.a)return b<u.b;
        return a<u.a;       
    }    //运算符重载实现结构体排序

}p[N];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i].a>>p[i].b>>p[i].c;
    sort(p+1,p+n+1);//sort默认排序结果从小到大
    reverse(p+1,p+n+1);//reverse反转数组使从大到小输出
for(int i=1;i<=n;i++)cout<<p[i].a<<' '<<p[i].b<<' '<<p[i].c<<'\n';

}


int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    while(_--)solve();
    system("pause");
    return 0;
}