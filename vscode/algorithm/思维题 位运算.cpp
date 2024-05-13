#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 2e5+9;
int xorPrefixsum[N];
//性质： 一个更大的数必能由更小的两个数异或得到
/*
 void solve()
 {
  int a,b;
  cin>>a>>b;

  int k=0;
 for(int i=1;i<a;i++)k^=i;
  if(k==b)cout<<a<<endl;
  else if((k^a)==b)cout<<a+2<<endl;
  else cout<<a+1<<endl;
 

 }   
*/

//时间超限 多次询问题要注意利用前缀和减少时间复杂度

void solve()
{
int a,b;cin>>a>>b;
int k=xorPrefixsum[a-1];
if(k==b)cout<<a<<endl;
else if((k^a)==b)cout<<a+2<<endl;
else cout<<a+1<<endl;


}



int main()
{

ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

for(int i=1;i<=N;i++)xorPrefixsum[i]=xorPrefixsum[i-1]^i;
    int _;cin>>_;
    while(_--)solve();  //多次询问

 system("pause");
    return 0;
}