#include<bits/stdc++.h>

using namespace std;


struct Plane
{
	int t, d, l;
	
	Plane(int t, int d, int l) : t(t), d(d), l(l) {}
		
	
	bool operator < (const Plane & other) const
	{
		return t + d < other.t + other.d;
	}
};


int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int T;cin >> T;
	vector<Plane> a;
	
	while(T--) // T组数据 
	{
		int N;cin>>N; // N架飞机 
		
		for (int i = 0; i < N; i++) // 输入数据结构体插入集合排序 
		{
			int t,d,l;cin>>t>>d>>l;
			a.push_back(Plane(t,d,l));
		}
		
		sort(a.begin(), a.end());
		
		
		bool flag = false;
		if (a[0].t + a[0].l > a[1].t + a[1].d)
			{
				cout << "NO" <<'\n';
				break;
			}
		
		for (int i = 1; i < N - 1; i++)
		{
			if (a[i - 1].t + a[i - 1].l + a[i].l > a[i + 1].t + a[i + 1].d)
			{
				cout << "NO" <<'\n';
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout<<"YES"<<'\n';
		}
		
		a.clear();
		
		
	}
	

	return 0;
	
}
