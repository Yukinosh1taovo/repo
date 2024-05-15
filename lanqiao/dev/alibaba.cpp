#include<bits/stdc++.h>

using namespace std;


struct Node
{
	double m, v;
	double avg;
};

Node a[110];

bool cmp (Node x, Node y)
{
	return x.avg > y.avg;
}

int main()
{
	int n, t;cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].m >> a[i].v;
		a[i].avg = a[i].v / a[i].m;
	}
	
	sort (a + 1, a + 1 + n, cmp);
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (t >= a[i].m)
		{
			sum += a[i].v;
			t -= a[i].m;
		}
		
		else
		{
			sum = sum + t * 1.0 * a[i].avg;
			break;
		}
	}
	printf("%.2f", sum);
	return 0;
	
}
