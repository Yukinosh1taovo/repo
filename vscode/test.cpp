#include <bits/stdc++.h>

using namespace std;

#define ll long long int

struct Para
{
    int k, b, x, increase;

    Para(int k, int b, int x, int increase) : k(k), b(b), x(x), increase(increase) {}
    bool operator<(const Para &other) const
    {
        return increase < other.increase;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    priority_queue<Para> pq;
    Para cost(0, 0, 0, 0);

    for (int i = 0; i < M; i++)
    {
        cin >> cost.k >> cost.b;
        cost.increase = cost.b + cost.k;
        if (cost.increase <= 0)
            continue;

        cost.x += 1;
        pq.push(cost);
    }

    ll money = 0, person;

    for (person = 0; !pq.empty() && person < N; person++)
    {
        cost = pq.top();
        pq.pop();
        money += cost.increase;
        cost.increase = cost.k * (2 * cost.x + 1) + cost.b;
        if (cost.increase > 0)
        {
            cost.x += 1;
            pq.push(cost);
        }
    }
    cout << money;
    return 0;
}