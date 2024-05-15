#include<bits/stdc++.h>

using namespace std;

int N, T[11], D[11], L[11];

bool have_answer;  // 判断是否能够成功全部降落 

bool used[11];  // 记录每架飞机是否已经降落 

void dfs(int x, int tim)
{
	if (have_answer) return ;
	
	if (x == N)	
	{
		have_answer = 1;
		return ;
	} 
	
	for (int i = 1; i <= N; i++)
	{
		if (!used[i] && tim <= T[i] + D[i])
		{
			used[i] = 1;
			dfs(x + 1, max(T[i], tim) + L[i]);
			if (have_answer) return;
			used[i] = 0;
		}
	}

	
}

void solve()
{
	have_answer = 0;
	cin>>N;
	for (int i = 1; i <= N; i++) 
	{
		used[i] = 0;
		cin>>T[i]>>D[i]>>L[i]; 
	}
	
		dfs(0,0);
		if (have_answer) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	
	
	
}


int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int T;cin>>T;
	
	while (T--) solve();
	
	return 0;
}
